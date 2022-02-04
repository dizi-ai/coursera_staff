#include "iterator_range.h"
#include "search_server.h"

#include <algorithm>
#include <iterator>
#include <sstream>
#include <iostream>
#include <vector>
#include <numeric>

std::vector<std::string> SplitIntoWords(const std::string& line) {
    std::istringstream words_input(line);
    return {std::istream_iterator<std::string>(words_input), std::istream_iterator<std::string>()};
}

SearchServer::SearchServer(std::istream& document_input) {
    UpdateDocumentBase(document_input);
}

void SearchServer::UpdateDocumentBase(std::istream& document_input) {
    index = InvertedIndex(document_input);
}

void SearchServer::AddQueriesStream(std::istream& query_input, std::ostream& search_results_output) {
    const auto &documents = index.GetDocument();
    std::vector<size_t> docid_count(documents.size());

    for (std::string current_query; getline(query_input, current_query);) {
        for (const auto& word : SplitIntoWords(current_query)) {
            for (const auto& [docid, qty] : index.Lookup(word)) {
                docid_count[docid] += qty;
            }
        }

        std::vector<InvertedIndex::Entry> search_results(docid_count.size());
        for (size_t i = 0, I = search_results.size(); i < I; ++i) {
            search_results[i] = {i, docid_count[i]};
        }

        auto middleIt = Head(search_results, 5).end();
        partial_sort(begin(search_results), middleIt, end(search_results),
                     [](const InvertedIndex::Entry& lhs, const InvertedIndex::Entry& rhs) {
                         int64_t lhs_docid = lhs.docid;
                         int64_t rhs_docid = rhs.docid;
                         return std::make_pair(lhs.rating, -lhs_docid) >
                                std::make_pair(rhs.rating, -rhs_docid);
                     });

        search_results_output << current_query << ':';
        for (const auto& [docid, hitcount] : Head(search_results, 5)) {
            if (hitcount == 0) {
                break;
            }

            search_results_output << " {"
                                  << "docid: " << docid << ", "
                                  << "hitcount: " << hitcount << '}';
        }
        search_results_output << '\n';

        fill(begin(docid_count), end(docid_count), 0);
    }
}

InvertedIndex::InvertedIndex(std::istream& stream) {
    for(std::string current_document; getline(stream, current_document); ){
        docs.push_back(move(current_document));
        size_t docid = docs.size() - 1;
        for (std::string word : SplitIntoWords(docs.back()) ) {
            auto& docids = index[word];
            if (!docids.empty() && docids.back().docid==docid ) {
                docids.back().rating++;
            } else {
                docids.push_back({docid, 1});
            }
        }
    }
}

const std::vector<InvertedIndex::Entry>& InvertedIndex::Lookup(const std::string& word) const {
    static std::vector<InvertedIndex::Entry> result;
    if (auto it = index.find(word); it != index.end()) {
        return it->second;
    } else {
        return result;
    }
}
