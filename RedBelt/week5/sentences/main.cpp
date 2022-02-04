#include "test_runner.h"

#include <vector>

using namespace std;

// Объявляем Sentence<Token> для произвольного типа Token
// синонимом vector<Token>.
// Благодаря этому в качестве возвращаемого значения
// функции можно указать не малопонятный вектор векторов,
// а вектор предложений — vector<Sentence<Token>>.
template <typename Token>
using Sentence = std::vector<Token>;
// Класс Token имеет метод bool IsEndSentencePunctuation() const
template <typename Token>
std::vector<Sentence<Token>> SplitIntoSentences(std::vector<Token> tokens) {
    std::vector<Sentence<Token>> toret;
    toret.reserve(tokens.size());
    Sentence<Token> sentence;
    size_t count=0;
    for (auto& i : tokens){
        if(count!=tokens.size()-1) {
            if (i.IsEndSentencePunctuation()&&!tokens[count+1].IsEndSentencePunctuation()) {
                sentence.push_back(std::move(i));
                toret.push_back(std::move(sentence));
                sentence.clear();
            } else {
                sentence.push_back(std::move(i));
            }
        }
        else{
            sentence.push_back(std::move(i));
            toret.push_back(std::move(sentence));
            sentence.clear();
        }
        count++;
    }
    toret.shrink_to_fit();
    return toret;
}


struct TestToken {
    string data;
    bool is_end_sentence_punctuation = false;

    bool IsEndSentencePunctuation() const {
        return is_end_sentence_punctuation;
    }
    bool operator==(const TestToken& other) const {
        return data == other.data && is_end_sentence_punctuation == other.is_end_sentence_punctuation;
    }
};

ostream& operator<<(ostream& stream, const TestToken& token) {
    return stream << token.data;
}

// Тест содержит копирования объектов класса TestToken.
// Для проверки отсутствия копирований в функции SplitIntoSentences
// необходимо написать отдельный тест.
void TestSplitting() {
    ASSERT_EQUAL(SplitIntoSentences(std::vector<TestToken>({{"Split"}, {"into"}, {"sentences"}, {"!"}})),
                 std::vector<Sentence<TestToken>>({{{"Split"}, {"into"}, {"sentences"}, {"!"}}}));


    ASSERT_EQUAL(SplitIntoSentences(std::vector<TestToken>({{"Split"}, {"into"}, {"sentences"}, {"!", true}})),
                 std::vector<Sentence<TestToken>>({{{"Split"}, {"into"}, {"sentences"}, {"!", true}}}));


    ASSERT_EQUAL(SplitIntoSentences(std::vector<TestToken>({{"Split"}, {"into"}, {"sentences"}, {"!", true},
                                                            {"!", true}, {"Without"}, {"copies"}, {".", true}})),

                 std::vector<Sentence<TestToken>>({{{"Split"}, {"into"}, {"sentences"},
                                                           {"!", true}, {"!", true}}, {{"Without"}, {"copies"}, {".", true}},}));


    ASSERT_EQUAL(SplitIntoSentences(std::vector<TestToken>({ { "!", true }, { "!", true }, { "?", true },
                                                             { "Split" }, { "into" }, { "sentences" }, { "!", true }, { "Without" }, { "copies" } })),

                 std::vector<Sentence<TestToken>>({ { { "!", true }, { "!", true }, {"?", true} },
                                                    {{ "Split" }, { "into" }, { "sentences" }, { "!", true }}, {{ "Without" }, { "copies" }} }));


    ASSERT_EQUAL(SplitIntoSentences(std::vector<TestToken>({ { "!", true }, { "!", true }, { "?", true } })),

                 std::vector<Sentence<TestToken>>({ { { "!", true }, { "!", true }, {"?", true} } }));


    ASSERT_EQUAL(SplitIntoSentences(std::vector<TestToken>({ {"!"}, {"!"}, {"?"} })),

                 std::vector<Sentence<TestToken>>({ { {"!"}, {"!"}, {"?"} } }));


    ASSERT_EQUAL(SplitIntoSentences(std::vector<TestToken>()), std::vector<Sentence<TestToken>>());


    ASSERT_EQUAL(SplitIntoSentences(std::vector<TestToken>({ { "!", true }, { "!", true }, { "?", true },
                                                             { "Split" }, { "into" }, { "sentences" }, { "!", true }, { "Without" }, { "copies" }, { "!", true } })),

                 std::vector<Sentence<TestToken>>({ { { "!", true }, { "!", true }, {"?", true} },
                                                    {{ "Split" }, { "into" }, { "sentences" }, { "!", true }}, {{ "Without" }, { "copies" }, { "!", true }} }));
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestSplitting);
    return 0;
}
