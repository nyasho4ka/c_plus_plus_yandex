#include <sstream>
#include <iostream>
#include <exception>
using namespace std;

template <typename T, typename U>
void AssertEqual(const T& t, const U& u, const string& hint) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u << " Hint: " << hint;
        throw runtime_error();
    }
}

void Assert(bool value, const string& hint) {
    AssertEqual(value, true, hint);
}

template <typename TestFunc>
void RunTest(TestFunc func, const string& test_name) {
    try {
        func();
    } catch (runtime_error& e) {
        cout << "Test " << test_name << " failed: " << e.what() << endl;
    }
}
