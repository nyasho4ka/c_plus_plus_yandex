#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

class Person {
    public:
        void ChangeFirstName(int year, const string& first_name)
        {
            first_names[year] = first_name;
        }
        void ChangeLastName(int year, const string& last_name)
        {
            last_names[year] = last_name;
        }
        string GetFullName(int year)
        {
            return "NULL";
        }
        string GetFullNameWithHistory(int year)
        {
            string first_name = GetNameWithHistory(year, first_names);
            string last_name = GetNameWithHistory(year, last_names);

            if (first_name.empty() && last_name.empty())
            {
                return "undefined";
            }
            else if (first_name.empty())
            {
                return last_name + " with unknown first name history";
            }
            else if (last_name.empty())
            {
                return first_name + " with unknown last name history";
            }
            return first_name + ' ' + last_name;
        }
    private:
        map<int, string> first_names;
        map<int, string> last_names;

        string GetNameWithHistory(int year, map<int, string>& names)
        {
            bool is_first = true;
            string name_history = "";
            for (const auto& name : names)
            {
                if (name.first <= year)
                {
                    if (is_first)
                    {
                        name_history = name.second + name_history;   
                        is_first = false;
                    }
                    else
                    {
                        name_history = name.second + ' ' + name_history;
                    }
                }
            }
            return name_history;
        }
};


int main() {
  Person person;

  person.ChangeFirstName(1900, "Eugene");
  person.ChangeLastName(1900, "Sokolov");
  person.ChangeLastName(1910, "Sokolov");
  person.ChangeFirstName(1920, "Evgeny");
  person.ChangeLastName(1930, "Sokolov");
  cout << person.GetFullNameWithHistory(1940) << endl;
  
  return 0;
}
