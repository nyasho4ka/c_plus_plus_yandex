#include <iostream>
#include <string>
using namespace std;


void EnsureEqual(const string& leftString, const string& rightString) {
    if (leftString != rightString) {
        throw runtime_error(leftString + " != " + rightString);
    }
}

void TryEnsureEqual(const string& leftString, const string& rightString) {
    try{
        EnsureEqual(leftString, rightString);
    } catch(exception& ex) {
        cout << ex.what() << endl;
    }
}

int main() {
    string firstString = "C++ Yellow";
    string secondString = "C++ White";
    string thirdString = "C++ Red";
    TryEnsureEqual(firstString, secondString);
    TryEnsureEqual(secondString, secondString);
    TryEnsureEqual(thirdString, firstString);
    TryEnsureEqual(thirdString, thirdString);
}