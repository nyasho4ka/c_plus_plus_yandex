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

Person GetFillingPerson() {
    Person person;
    person.ChangeFirstName(1900, "Misha");
    person.ChangeFirstName(1905, "Pasha");
    person.ChangeFirstName(1910, "Dasha");
    person.ChangeFirstName(1915, "Sasha");
    person.ChangeFirstName(1920, "Gosha");
    person.ChangeLastName(1901, "Kulikov");
    person.ChangeLastName(1906, "Polikov");
    person.ChangeLastName(1911, "Jolikov");
    person.ChangeLastName(1916, "Yolikov");
    person.ChangeLastName(1921, "Bolikov");
    return person;
}

Person GetAnotherPerson() {
    Person person;
    person.ChangeFirstName(1901, "Misha");
    person.ChangeFirstName(1906, "Pasha");
    person.ChangeFirstName(1911, "Dasha");
    person.ChangeFirstName(1916, "Sasha");
    person.ChangeFirstName(1921, "Gosha");
    person.ChangeLastName(1900, "Kulikov");
    person.ChangeLastName(1905, "Polikov");
    person.ChangeLastName(1910, "Jolikov");
    person.ChangeLastName(1915, "Yolikov");
    person.ChangeLastName(1920, "Bolikov");
    return person;
}


void TestPerson() {
    Person person = GetFillingPerson();
    string incognito = "Incognito";
    string unknown_last_name = " with unknown last name";
    AssertEqual(person.GetFullName(1899), incognito);
    AssertEqual(person.GetFullName(1900), "Misha" + unknown_last_name);
    AssertEqual(person.GetFullName(1901), "Misha Kulikov");
    AssertEqual(person.GetFullName(1923), "Gosha Bolikov");
}

void TestAnotherPerson() {
    Person person = GetAnotherPerson();
    string incognito = "Incognito";
    string unknown_first_name = " with unknown first name";
    AssertEqual(person.GetFullName(1899), incognito);
    AssertEqual(person.GetFullName(1900), "Kulikov" + unknown_first_name);
    AssertEqual(person.GetFullName(1901), "Misha Kulikov");
    AssertEqual(person.GetFullName(1923), "Gosha Bolikov");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestPerson, "Test Person");
  runner.RunTest(TestAnotherPerson, "Test Another Person");
  return 0;
}
