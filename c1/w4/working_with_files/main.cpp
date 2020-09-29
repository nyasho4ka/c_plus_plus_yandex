#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void ReadFile(const string& path) {
    ifstream input(path);
    if (input) {
        string line;
        while (getline(input, line)) {
            cout << line << endl;
        }
    } else {
        cout << "ERROR! SUCH FILE DOESN'T EXISTS" << endl;
    }
}


int main() {
    string path;
    cout << "Please, enter the file name: ";
    cin >> path;
    ReadFile(path);
    return 0;
}