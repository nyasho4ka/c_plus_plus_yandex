#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;


class Person {
    public:
        void ChangeFirstName(int year, const string& first_name)
        {
            year_to_first_name[year] = first_name;
        }
        void ChangeLastName(int year, const string& last_name)
        {
            year_to_last_name[year] = last_name;
        }
        string GetFullName(int year)
        {
            string first_name = FindNameByYear(year_to_first_name, year);
            string last_name = FindNameByYear(year_to_last_name, year);

            if (first_name.empty() && last_name.empty())
            {
                return "Incognito";
            }
            else if (first_name.empty())
            {
                return last_name + " with unknown first name";
            }
            else if (last_name.empty())
            {
                return first_name + " with unknown last name";
            }
            return first_name + " " + last_name;
        }
    private:
        map<int, string> year_to_first_name, year_to_last_name;
        string FindNameByYear(map<int, string>& names, int year)
        {
            string name;

            for (auto item : names)
            {
                if (item.first <= year)
                {
                    name = item.second;
                }
                else
                {
                    break;
                }
            }

            return name;
        }
};


int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  return 0;
}