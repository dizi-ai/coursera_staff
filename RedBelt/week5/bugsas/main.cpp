#include "test_runner.h"
#include <map>
#include <future>
#include <string>
#include <functional>
#include <iterator>
#include <vector>
using namespace std;
struct Stats {
  map<string, int> word_frequences;

  void operator += (const Stats& other){
      for (auto& [word, frequency] : other.word_frequences) {
          word_frequences[word] += frequency;
      }
  }
};

Stats ExploreLine(const set<string>& key_words, const string& line) {
    Stats result;
    std::istringstream is(line);
    std::string temp;
    while (is>>temp){
        if (result.word_frequences.find(temp)!=result.word_frequences.end()){
            result.word_frequences.at(temp)++;
        }
        else if (key_words.find(temp)!=key_words.end())
            result.word_frequences[temp]=1;
    }

    return result;
}

Stats ExploreKeyWordsSingleThread(const set<string>& key_words, istream& input) {
  Stats result;
  for (string line; getline(input, line); ) {
    result += ExploreLine(key_words, line);
  }
  return result;
}
Stats ExploreKeyWords(const set<string>& key_words, istream& input) {
    Stats ret;
    vector<future<Stats>> futures;
    size_t num_lines = 0;
    const auto num_threads = std::thread::hardware_concurrency();
    std::vector<std::stringstream> streams(num_threads);

    std::string line;
    while (std::getline(input, line))
    {
        streams[num_lines % num_threads] << line << '\n';
        ++num_lines;
    }

    for (auto& h : streams)
        futures.push_back(async(ExploreKeyWordsSingleThread,ref(key_words),ref(h)));
    for (auto& f : futures)
        ret+=f.get();
    return ret;
}

void TestBasic() {
    const set<string> key_words = {"yangle", "rocks", "sucks", "all"};

    stringstream ss;
    ss << "this new yangle service really rocks\n";
    ss << "It sucks when yangle isn't available\n";
    ss << "10 reasons why yangle is the best IT company\n";
    ss << "yangle rocks others suck\n";
    ss << "Goondex really sucks, but yangle rocks. Use yangle\n";

    const auto stats = ExploreKeyWords(key_words, ss);
    const map<string, int> expected = {
    {"yangle", 6},
    {"rocks", 2},
    {"sucks", 1}
    };
    ASSERT_EQUAL(stats.word_frequences, expected);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestBasic);
}