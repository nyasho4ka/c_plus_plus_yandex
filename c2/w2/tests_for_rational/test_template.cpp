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
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
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

void TestDefaultConstructor() {
    Rational rational = Rational();
    AssertEqual(rational.Numerator(), 0, "Default constructor");
    AssertEqual(rational.Denominator(), 1, "Default constructor");
}


void TestZeroNumerator() {
    Rational rational = Rational(0, 14);
    AssertEqual(rational.Numerator(), 0, "Zero numerator");
    AssertEqual(rational.Denominator(), 1, "Zero numerator");
}


void TestPositive() {
    Rational rational = Rational(4, 6);
    AssertEqual(rational.Numerator(), 2, "Positive");
    AssertEqual(rational.Denominator(), 3, "Positive");
}


void TestNegativeDenominator() {
    Rational rational = Rational(4, -6);
    AssertEqual(rational.Numerator(), -2, "Negative Denominator");
    AssertEqual(rational.Denominator(), 3, "Negative Denominator");
}


void TestNegativeNumerator() {
    Rational rational = Rational(-4, 6);
    AssertEqual(rational.Numerator(), -2, "Negative Numerator");
    AssertEqual(rational.Denominator(), 3, "Negative Numerator");
}

void TestNegativeBoth() {
    Rational rational = Rational(-4, -6);
    AssertEqual(rational.Numerator(), 2, "Negative both");
    AssertEqual(rational.Denominator(), 3, "Negative both");
}


int main() {
  TestRunner runner;
  runner.RunTest(TestDefaultConstructor, "TestDefaultConstructor");
  runner.RunTest(TestZeroNumerator, "TestZeroNumerator");
  runner.RunTest(TestPositive, "TestPositive");
  runner.RunTest(TestNegativeDenominator, "TestNegativeDenominator");
  runner.RunTest(TestNegativeNumerator, "TestNegativeNumerator");
  runner.RunTest(TestNegativeBoth, "TestNegativeBoth");
  return 0;
}
