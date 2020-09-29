#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


void ReadNumbersWithPrecision(const string& path, int precision) {
    ifstream input(path);
    if (input) {
        cout << fixed << setprecision(precision);
        double number;
        while (input >> number) {
            cout << number << endl;
        }
    } else {
        cout << "Error! Such file doesn't exists" << endl;
    }
}


int main() {
    string path;
    int precision;
    cout << "Please, enter the file path: ";
    cin >> path;
    cout << "Enter the number precision: ";
    cin >> precision;
    ReadNumbersWithPrecision(path, precision);    
}