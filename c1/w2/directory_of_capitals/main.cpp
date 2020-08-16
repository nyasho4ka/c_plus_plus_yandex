#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

void ChangeCapital(map<string, string>& country_capital, string country, string new_capital)
{
    if (country_capital.count(country) == 0)
    {
        cout << "Introduce new country " << country << " with capital " << new_capital << endl;
    }
    else if (country_capital[country] == new_capital)
    {
        cout << "Country " << country << " hasn't changed its capital" << endl;
        return;
    }
    else
    {
        cout << "Country " << country << " has changed its capital from " << country_capital[country] << " to " <<  new_capital << endl;
    }
    country_capital[country] = new_capital;
}

void Rename(map<string, string>& country_capital, string old_country_name, string new_country_name)
{
    if  (
        old_country_name == new_country_name ||
        country_capital.count(old_country_name) == 0 ||
        country_capital.count(new_country_name) > 0
        )
    {
        cout << "Incorrect rename, skip" << endl;
    }
    else 
    {   
        cout << "Country " << old_country_name 
        << " with capital " << country_capital[old_country_name]
        << " has been renamed to " << new_country_name << endl;
        string temp_capital = country_capital[old_country_name];
        country_capital.erase(old_country_name);
        country_capital[new_country_name] = temp_capital;
    }
}

void About(map<string, string>& country_capital, string country)
{
    if (country_capital.count(country) == 0) 
    {
        cout << "Country " << country << " doesn't exist" << endl;
    }
    else
    {
        cout << "Country " << country << " has capital " << country_capital[country] << endl;
    }
}

void Dump(const map<string, string>& country_capital)
{  
    if (country_capital.size() == 0)
    {
        cout << "There are no countries in the world" << endl;
    }
    else
    {
        for (auto item : country_capital)
        {
            cout << item.first << "/" << item.second << " ";
        }
        cout << endl;
    }
}

int GetNumberOfRequests()
{
    int Q;
    cout << "Enter the number of requests: ";
    cin >> Q;
    return Q;
}

map<string, string> InitCountryCapitalMap()
{   
    map<string, string> country_capital;
    return country_capital;
}

string ReadRequest()
{
    string request;
    cin >> request;
    return request;
}

void ReadRequests()
{   
    int Q = GetNumberOfRequests();
    map<string, string> country_capital = InitCountryCapitalMap();

    string request;
    for (int i = 0; i < Q; i++)
    {
        request = ReadRequest();
        if (request == "CHANGE_CAPITAL")
        {
            string country;
            string new_capital;
            cin >> country >> new_capital;
            ChangeCapital(country_capital, country, new_capital);
        }
        else if (request == "RENAME")
        {
            string old_country_name;
            string new_country_name;
            cin >> old_country_name >> new_country_name;
            Rename(country_capital, old_country_name, new_country_name);
        }
        else if (request == "ABOUT")
        {
            string country;
            cin >> country;
            About(country_capital, country);
        }
        else if (request == "DUMP")
        {
            Dump(country_capital);
        }
    }
}

int main()
{
    ReadRequests();
    return 0;
}