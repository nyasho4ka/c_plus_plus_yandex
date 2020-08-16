#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int GetNumbersNumber()
{
    int N;
    cin >> N;
    return N;
}

void ReadStrings(vector<string>& strings)
{
    for (int i = 0; i < strings.size(); i++)
    {
        cin >> strings[i];
    }
}

void PrintVector(const vector<string>& strings)
{
    for (auto str : strings)
    {
        cout << str << " ";
    }
    cout << endl;
}

void StringToLower(string& str)
{
    for (int i = 0; i < str.size(); i++)
    {
        str[i] = tolower(str[i]);
    }
}

bool CompareWithoutCase(string str1, string str2)
{
    StringToLower(str1);
    StringToLower(str2);
    return str1 < str2;
}

int main()
{
    int N = GetNumbersNumber();
    vector<string> strings(N);
    ReadStrings(strings);
    PrintVector(strings);
    sort(strings.begin(), strings.end(), CompareWithoutCase);
    PrintVector(strings);
}