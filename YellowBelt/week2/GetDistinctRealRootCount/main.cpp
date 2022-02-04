#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        }
        catch (exception& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        }
        catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

int GetDistinctRealRootCount(double a, double b, double c) {
    if (a == 0 && b == 0)
        return 0;
    if (a == 0 && b != 0 )
        return 1;
    double d = b * b - 4 * a * c;
    if (d < 0) {
        return 0;
    }
    if (d == 0) {
        return 1;
    }
    if (d > 0)
        return 2;
    return 0;
}
void Test1() {
    AssertEqual(GetDistinctRealRootCount(5, -9, -2), 2, "Incorrect number of roots: 5, -9, -2" );
    AssertEqual(GetDistinctRealRootCount(2, -11, 5), 2, "Incorrect number of roots: 2, -11, 5");
    AssertEqual(GetDistinctRealRootCount(5, 11, 2), 2, "Incorrect number of roots: 5, 11, 2");
    AssertEqual(GetDistinctRealRootCount(3, -7, 2), 2, "Incorrect number of roots: 3, -7, 2");
    AssertEqual(GetDistinctRealRootCount(64, -63, -1), 2, "Incorrect number of roots: 64, -63, -1");
    AssertEqual(GetDistinctRealRootCount(2, 7, 3), 2, "Incorrect number of roots: 2, 7, 3");
    AssertEqual(GetDistinctRealRootCount(3, 5, -2), 2, "Incorrect number of roots: 3, 5, -2");
    AssertEqual(GetDistinctRealRootCount(2, -9, 9), 2, "Incorrect number of roots: 2, -9, 9");
    AssertEqual(GetDistinctRealRootCount(9, -10, 1), 2, "Incorrect number of roots: 9, -10, 1");
    AssertEqual(GetDistinctRealRootCount(4, -2, 0), 2, "Incorrect number of roots: 4, -2, 0");
    AssertEqual(GetDistinctRealRootCount(4, 2, 0), 2, "Incorrect number of roots: 4, 2, 0");
    AssertEqual(GetDistinctRealRootCount(1, 0, -4), 2, "Incorrect number of roots: 1, 0, 4" );
    AssertEqual(GetDistinctRealRootCount(4, 7, 3), 2, "Incorrect number of roots:  4, 7, 3");
}
void Test2() {
    AssertEqual(GetDistinctRealRootCount(4, -4, 1), 1, "Incorrect number of roots: 4, -4, 1");
    AssertEqual(GetDistinctRealRootCount(0, -10, 1), 1, "Incorrect number of roots: 0, -10, 1");
    AssertEqual(GetDistinctRealRootCount(0, -10, 0), 1, "Incorrect number of roots: 0, -10, 0");
    AssertEqual(GetDistinctRealRootCount(4, 0, 0), 1, "Incorrect number of roots: 4, 0, 0");
    AssertEqual(GetDistinctRealRootCount(-4, 0, 0), 1, "Incorrect number of roots: -4, 0, 0");

}
void Test3() {
    AssertEqual(GetDistinctRealRootCount(1, 0, 4), 0, "Incorrect number of roots: 1, 0, 4");
    AssertEqual(GetDistinctRealRootCount(2, -3, 2), 0, "Incorrect number of roots: 2, -3, 2");
    AssertEqual(GetDistinctRealRootCount(0, 0, 1), 0, "Incorrect number of roots: 0, 0, 1");
}
int main() {
    {
        TestRunner tr;
        tr.RunTest(Test1, "2 roots");
        tr.RunTest(Test2, "1 root");
        tr.RunTest(Test3, "no roots");
    }
    return 0;
}