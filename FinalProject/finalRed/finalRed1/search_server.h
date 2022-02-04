#pragma once

#include <istream>
#include <ostream>
#include <set>
#include <list>
#include <vector>
#include <map>
#include <string>
#include <deque>
#include <mutex>
#include <future>

class InvertedIndex {
public:
    InvertedIndex()=default;
    explicit InvertedIndex(std::istream& is);
    struct Entry {
        size_t docid;
        size_t rating;
    };
    const std::vector<Entry>& Lookup(const std::string& word) const;

    const std::deque<std::string>& GetDocument() const {
        return docs;
    }
private:
    std::map <std::string, std::vector<Entry>> index;
    std::deque<std::string> docs;
};

class SearchServer {
public:
    SearchServer() = default;
    explicit SearchServer(std::istream& document_input);
    void UpdateDocumentBase(std::istream& document_input);
    void AddQueriesStream(std::istream& query_input, std::ostream& search_results_output);

private:
    InvertedIndex index;
};
