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

void TestEmpty() {
    {
        Rational r;
        AssertEqual(r.Numerator(),0, "Empty1: 0");
        AssertEqual(r.Denominator(), 1, "Empty1: 1");

    }
    {
        Rational r(0,2);
        AssertEqual(r.Numerator(), 0, "Empty1: 0");
        AssertEqual(r.Denominator(), 1, "Empty1: 1");

    }
}
void TestReduction() {
    {
        Rational r(12,24);
        AssertEqual(r.Numerator(), 1, "Reduction1 Num: 1");
        AssertEqual(r.Denominator(), 2, "Reduction1 Den: 2");
    }
    {
        Rational r(100, 120);
        AssertEqual(r.Numerator(), 5, "Reduction2 Num: 5");
        AssertEqual(r.Denominator(), 6, "Reduction2 Den: 6");
    }
    {
        Rational r(100, -120);
        AssertEqual(r.Numerator(), -5, "Reduction3 Num: -5");
        AssertEqual(r.Denominator(), 6, "Reduction3 Den: 6");
    }
    {
        Rational r(-100, 120);
        AssertEqual(r.Numerator(), -5, "Reduction4 Num: -5");
        AssertEqual(r.Denominator(), 6, "Reduction4 Den: 6");
    }
    {
        Rational r(2, 2);
        AssertEqual(r.Numerator(), 1, "Reduction5 Num: 1");
        AssertEqual(r.Denominator(), 1, "Reduction5 Den: 1");
    }
    {
        Rational r(2, -2);
        AssertEqual(r.Numerator(), -1, "Reduction5 Num: -1");
        AssertEqual(r.Denominator(), 1, "Reduction5 Den: 1");
    }
    {
        Rational r(-2, 2);
        AssertEqual(r.Numerator(), -1, "Reduction5 Num: -1");
        AssertEqual(r.Denominator(), 1, "Reduction5 Den: 1");
    }
}
/*
void TestMax() {
    {
        Rational r(0, INT_MAX);
        AssertEqual(r.Numerator(), 0, "Max1 Num: 0");
        AssertEqual(r.Denominator(), INT_MAX, "Max1 Den: INT_MAX");
    }
    {
        Rational r(INT_MAX, INT_MAX);
        AssertEqual(r.Numerator(), 1, "Max2 Num: INT_MAX");
        AssertEqual(r.Denominator(), 1, "Max2 Den: INT_MAX");
    }
    {
        Rational r(INT_MAX, -INT_MAX);
        AssertEqual(r.Numerator(), -1, "Max3 Num: -1");
        AssertEqual(r.Denominator(), 1, "Max3 Den: 1");
    }
    {
        Rational r(0, INT_MIN);
        AssertEqual(r.Numerator(), -0, "Max4 Num: -0");
        AssertEqual(r.Denominator(), INT_MAX, "Max4 Den: INT_MAX");
    }
    {
        Rational r(0, INT_MIN);
        AssertEqual(r.Numerator(), -0, "Max5 Num: -0");
        AssertEqual(r.Denominator(), INT_MAX, "Max5 Den: INT_MAX");
    }
    {
        Rational r(INT_MAX, INT_MIN);
        AssertEqual(r.Numerator(), -1, "Max6 Num: -1");
        AssertEqual(r.Denominator(), 1, "Max6 Den: 1");
    }
    {
        Rational r(INT_MIN, INT_MIN);
        AssertEqual(r.Numerator(), 1, "Max7 Num: 1");
        AssertEqual(r.Denominator(), 1, "Max7 Den: 1");
    }
    {
        Rational r(INT_MIN, INT_MAX);
        AssertEqual(r.Numerator(), -1, "Max8 Num: -1");
        AssertEqual(r.Denominator(), 1, "Max8 Den: 1");
    }
}
 */
int main() {
    {
        TestRunner tr;
        tr.RunTest(TestEmpty, "Empty");
        tr.RunTest(TestReduction, "Reduction");
        //tr.RunTest(TestMax, "Max");
    }

    return 0;
}