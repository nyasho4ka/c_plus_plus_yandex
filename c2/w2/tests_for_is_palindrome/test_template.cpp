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

bool IsPalindrom(const string& str) {
  // Вы можете вставлять сюда различные реализации функции,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
}

void TestEmpty() {
    Assert(IsPalindrom(""), "Empty string");
}

void TestOneSpace() {
    Assert(IsPalindrom(" "), "Empty string");
}

void TestSixSpaces() {
    Assert(IsPalindrom("      "), "Empty string");
}

void TestOneA() {
    Assert(IsPalindrom("A"), "One char string");
}

void TestOneComma() {
    Assert(IsPalindrom(","), "One char string");
}


void TestAbcbA() {
    Assert(IsPalindrom("AbcbA"), "Full string");
}

void TestAb2SbA() {
    Assert(IsPalindrom("Ab  bA"), "Full string");
}

void TestCPSPC() {
    Assert(IsPalindrom(",. .,"), "Full string");
}

void Testpooop() {
    Assert(IsPalindrom("pooop"), "Full string");
}

void Testabcde() {
    Assert(!IsPalindrom("abcde"), "Full string");
}

void TestAbBA() {
    Assert(!IsPalindrom("Ab]A"), "Full string");
}

void TestSigns(){
    Assert(!IsPalindrom(",.!,"), "Full string");
}

void TestStrange() {
    Assert(!IsPalindrom("],,.asda"), "Full string");
}

void TestThreeSevens() {
    Assert(IsPalindrom("   7    7    7   "), "Digits");
}

void TestFourSevens() {
    Assert(IsPalindrom("     77     77     "), "Digits");
}

void TestOneTwoThree() {
    Assert(!IsPalindrom("123"), "Digits");
}

void TestNotEqualSpaces() {
    Assert(!IsPalindrom("  AbA "), "Spaces");
}

void TestSpacesAndChars() {
    Assert(!IsPalindrom("  bcd  "), "Spaces");
}

void Test1() {
    Assert(!IsPalindrom("   b "), "   b ");
}

void Test2() {
    Assert(!IsPalindrom("  b b "), "  b b ");
}

void Test3() {
    Assert(!IsPalindrom("Nabcba"), "Nabcba");
}

void Test4() {
    Assert(!IsPalindrom("abcdehgjedcba"), "abcdehgjedcba");
}

void Test5() {
    Assert(!IsPalindrom("Abcba"), "Abcba");
}

void testAll(){
    AssertEqual(IsPalindrom(""),true);
    AssertEqual(IsPalindrom(" "),true);
    AssertEqual(IsPalindrom(" - - "),true);
    AssertEqual(IsPalindrom("s"),true);
    AssertEqual(IsPalindrom("mmooooomm"),true);
    AssertEqual(IsPalindrom("MMMoooMMM"),true);
    AssertEqual(IsPalindrom("mmmmOOOOmmmm"),true);
    AssertEqual(IsPalindrom("level"),true);
    AssertEqual(IsPalindrom("wasitacaroracatisaw"),true);
    AssertEqual(IsPalindrom("madam"),true);
    AssertEqual(IsPalindrom("mmmaaa   ddd   aaammm"),true);
    AssertEqual(IsPalindrom("maasdsaam"),true, "maasdsaam");
    AssertEqual(IsPalindrom("     aaasssaaa     "),true, "     aaasssaaa     ");
    AssertEqual(IsPalindrom("mmmooommM"),false, "mmmooommM");
    AssertEqual(IsPalindrom("maaa   dddaaammm"),false, "maaa   dddaaammm");
    AssertEqual(IsPalindrom("   aaasssaaa"),false, "   aaasssaaa");
    AssertEqual(IsPalindrom("sssssssaaaaaaa"),false, "sssssssaaaaaaa");
    AssertEqual(IsPalindrom("aaaaaaaaaasss"),false, "aaaaaaaaaasss");
    AssertEqual(IsPalindrom("s          "),false, "s          ");
    AssertEqual(IsPalindrom("          s"),false), "          s";
}


int main() {
  TestRunner runner;
  runner.RunTest(TestSpacesAndChars, "  bcd  ");
  runner.RunTest(TestNotEqualSpaces, "  AbA ");
  runner.RunTest(TestOneTwoThree, "123");
  runner.RunTest(TestFourSevens, "7777");
  runner.RunTest(TestThreeSevens, "777");
  runner.RunTest(TestStrange, "],,.asda");
  runner.RunTest(TestSigns, ",.!,");
  runner.RunTest(TestAbBA, "Ab]A");
  runner.RunTest(Testabcde, "abcde");
  runner.RunTest(Testpooop, "pooop");
  runner.RunTest(TestCPSPC, ",. .,");
  runner.RunTest(TestAb2SbA, "Ab  bA");
  runner.RunTest(TestAbcbA, "AbcbA");
  runner.RunTest(TestOneComma, ",");
  runner.RunTest(TestOneA, "A");
  runner.RunTest(TestSixSpaces, "      ");
  runner.RunTest(TestOneSpace, " ");
  runner.RunTest(TestEmpty, "");
  runner.RunTest(Test1, "   b ");
  runner.RunTest(Test2, "  b b ");
  runner.RunTest(Test3, "Nabcba");
  runner.RunTest(Test4, "abcdehgjedcba");
  runner.RunTest(Test5, "Abcba");
  runner.RunTest(testAll, "testAll");
  return 0;
}
