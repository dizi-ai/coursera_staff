#include "test_runner.h"
#include <sstream>
#include <string>

using namespace std;

class Logger {
public:
    explicit Logger(ostream& output_stream) : os(output_stream) { }
    void SetLogLine(bool value) {
        log_line = value;
    }
    void SetLogFile(bool value) {
        log_file= value;
    }
    [[nodiscard]] bool lline() const{
        return log_line;
    }
    [[nodiscard]] bool ffile() const{
        return log_file;
    }
    void Log(const string& message) {
        os<<message+"\n";
    }

private:
    ostream& os;
    bool log_line = false;
    bool log_file = false;
};

#define LOG(logger, message) { \
if (logger.ffile()&&logger.lline()){ \
    std::string temp=__FILE__; \
    temp+=":";                 \
    temp+=std::to_string(__LINE__); \
    temp+=" ";                 \
    temp+=message;\
    logger.Log(temp); \
    }\
else if (logger.ffile()) {     \
    std::string temp=__FILE__;\
    logger.Log(temp+ " "+ message);\
    }\
else if(logger.lline())             \
    logger.Log("Line "+std::to_string(__LINE__)+" "+message); \
else                           \
    logger.Log(message);\
}
/*
void TestLog() {
#line 1 "logger.cpp"

    ostringstream logs;
    Logger l(logs);
    LOG(l, "hello");

    l.SetLogFile(true);
    LOG(l, "hello");

    l.SetLogLine(true);
    LOG(l, "hello");

    l.SetLogFile(false);
    LOG(l, "hello");

    string expected = "hello\n";
    expected += "logger.cpp hello\n";
    expected += "logger.cpp:10 hello\n";
    expected += "Line 13 hello\n";
    ASSERT_EQUAL(logs.str(), expected);
}
*/
int main() {

    //TestRunner tr;
    //RUN_TEST(tr, TestLog);
}