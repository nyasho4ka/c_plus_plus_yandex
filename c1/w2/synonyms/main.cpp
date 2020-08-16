#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int GetRequestsNumber();
void ProcessRequests(int Q, map<string, set<string>>& synonyms);
string ReadRequest();
void Add(map<string, set<string>>& synonyms, string word1, string word2);
void Count(map<string, set<string>>& synonyms, string word);
void Check(map<string, set<string>>& synonyms, string word1, string word2);

int main()
{
    map<string, set<string>> synonyms;
    int Q = GetRequestsNumber();
    ProcessRequests(Q, synonyms);
    return 0;
}

int GetRequestsNumber()
{
    int Q;
    cin >> Q;
    return Q;
}

void ProcessRequests(int Q, map<string, set<string>>& synonyms)
{
    string request;
    for (int i = 0; i < Q; i++)
    {
        request = ReadRequest();
        if (request == "ADD")
        {
            string word1, word2;
            cin >> word1 >> word2;
            Add(synonyms, word1, word2);
        }
        else if (request == "COUNT")
        {
            string word;
            cin >> word;
            Count(synonyms, word);
        }
        else if (request == "CHECK")
        {
            string word1, word2;
            cin >> word1 >> word2;
            Check(synonyms, word1, word2);
        }
    }
}

string ReadRequest()
{
    string request;
    cin >> request;
    return request;
}

void Add(map<string, set<string>>& synonyms, string word1, string word2)
{
    synonyms[word1].insert(word2);
    synonyms[word2].insert(word1);
}
void Count(map<string, set<string>>& synonyms, string word)
{
    cout << synonyms[word].size() << endl;
}
void Check(map<string, set<string>>& synonyms, string word1, string word2)
{
    bool is_synonyms = 
        synonyms[word1].find(word2) != synonyms[word1].end();
    if (is_synonyms)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    cout << endl;
}