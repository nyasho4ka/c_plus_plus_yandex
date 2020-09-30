#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void GetTableSize(ifstream& input, int& rows, int&cols) {
    input >> rows >> cols;
}

void ReadTableRow(ifstream& input, int cols) {
    int currentNumber;
    bool is_first = true;
    for (int i = 0; i < cols; i++) {
        input >> currentNumber;
        input.ignore(1);
        cout << setw(10);
        if (is_first) {
            cout << currentNumber;
            is_first = false;
        }
        else {
            cout << ' ' << currentNumber;
        }
    }
}

void PrintTable(const string& path) {
    ifstream input(path);
    if (input) {
        int rows, cols;
        GetTableSize(input, rows, cols);
        for (int i = 0; i < rows; i++) {
            ReadTableRow(input, cols);
            // If it's not the last row in the table
            if (i != rows - 1) {
                cout << endl;
            }
        }
    } else {
        cout << "Error! Such file doesn't exists" << endl;
    }
}


int main() {
    string path;
    cout << "Please, enter the table path: ";
    cin >> path;
    PrintTable(path);
    return 0;
}