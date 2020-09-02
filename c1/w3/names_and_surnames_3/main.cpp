#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Person {
    public:
        Person(const string& firstName, const string& lastName, int year){
            ChangeFirstName(year, firstName);
            ChangeLastName(year, lastName);
            birth_year = year;
        }
        void ChangeFirstName(int year, const string& firstName) {
            if (year < birth_year) {
                return;
            }
            firstNames[year] = firstName;
        }
        void ChangeLastName(int year, const string& lastName) {
            if (year < birth_year) {
                return;
            }
            lastNames[year] = lastName;
        }
        string GetFullName(int year) {
            if (year < birth_year) {
                return "No person";
            }
            string firstName = GetName(year, firstNames);
            string lastName = GetName(year, lastNames);
            return GetResultString(firstName, lastName);
        }
        string GetFullNameWithHistory(int year) {
            if (year < birth_year) {
                return "No person";
            }
            string firstNameHistory = GetNameWithHistory(year, firstNames);
            string lastNameHistory = GetNameWithHistory(year, lastNames);
            return GetResultString(firstNameHistory, lastNameHistory);
        }
    private:
        int birth_year;
        map<int, string> firstNames;
        map<int, string> lastNames;
        
        string GetName(int year, const map<int, string> names) {
            string nameHistory = GetNameWithHistory(year, names);
            
            const int spacePosition = nameHistory.find(' ');
            if (spacePosition == string::npos) {
                return nameHistory;
            }
            
            string recentName = "";
            for (int i = 0; i < spacePosition; i++){
                recentName += nameHistory[i];
            }
            return recentName;
        }

        string GetNameWithHistory(int year, const map<int, string> names) {
            string nameHistory = formNameHistory(year, names);
            if (nameHistory.find(' ') != string::npos){
                insertBrackets(nameHistory);
            }
            return nameHistory;
        }
        
        string formNameHistory(int year, const map<int, string> names) {
            string nameHistory = "";
            string previously = "";
            bool is_first = true;
            for (auto name : names) {
                if (name.first <= year) {
                    if (name.second == previously){
                        continue;
                    }
                    if (is_first) {
                        nameHistory = name.second + nameHistory;
                        is_first = false;
                    }
                    else {
                        nameHistory = name.second + ' ' + nameHistory;
                    }
                    previously = name.second;
                }
            }
            return nameHistory;
        }

        void insertBrackets(string& nameHistory){
            int spaceIndex = 0;
            // find first space
            for (int i = 0; i < nameHistory.length(); i++) {
                if (nameHistory[i] == ' '){
                    spaceIndex = i;
                    break;
                }
            }
            // insert left bracket next to spaceIndex
            nameHistory.insert(spaceIndex+1, 1, '(');
            nameHistory += ')';
        }            

        string GetResultString(string& firstName, string& lastName) {
            if (firstName.empty() && lastName.empty()){
                return "Incognito";
            }
            if (firstName.empty()) {
                return lastName + " with unknown first name";
            }
            if (lastName.empty()) {
                return firstName + " with unknown last name";
            }

            return firstName + " " + lastName;
        }
};

int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
