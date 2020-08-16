#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int GetNumbersNumber();
vector<int> ReadNumbers(int);
void PrintVector(const vector<int>& vec);
bool CompareInts(int, int);

int main()
{
    int N = GetNumbersNumber();
    vector<int> numbers = ReadNumbers(N);
    PrintVector(numbers);
    sort(numbers.begin(), numbers.end(), CompareInts);
    PrintVector(numbers);
    return 0;
}

int GetNumbersNumber()
{
    int Q;
    cin >> Q;
    return Q;
}

vector<int> ReadNumbers(int N)
{
    vector<int> numbers(N);
    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }
    return numbers;
}

void PrintVector(const vector<int>& vec)
{
    for (auto elem : vec)
    {
        cout << elem << " ";
    }
    cout << endl;
}

bool CompareInts(int num1, int num2)
{
    return abs(num1) < abs(num2);
}