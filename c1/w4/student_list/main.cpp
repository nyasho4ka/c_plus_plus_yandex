#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;


struct Student {
    string name;
    string surname;
    int day;
    int month;
    int year;

    Student(string& new_name, string& new_surname, int new_day, int new_month, int new_year) {
        name = new_name;
        surname = new_surname;
        day = new_day;
        month = new_month;
        year = new_year;
    }
};


struct StudentList {
    vector<Student> students;
    
    void Fill(int studentsNumber, ifstream& input) {
        for (int i = 0; i < studentsNumber; i++) {
            string name;
            string surname;
            int day;
            int month;
            int year;
            input >> name >> surname >> day >> month >> year;
            students.push_back(Student(name, surname, day, month, year));
        }
    }

    void MakeQueries(int queryNumber, ifstream& input) {
        for (int i = 0; i < queryNumber; i++) {
            string query;
            int id;
            input >> query >> id;
            if (query == "date") {
                GetDateById(id);
            }
            else if (query == "name") {
                GetNameById(id);
            }
            else {
                cout << "Bad request" << endl;
            }
        }
    }

    void GetNameById(int id) {
        cout << students[id].name << ' ' << students[id].surname << endl;
    }

    void GetDateById(int id) {
        cout << students[id].year << ' ' << students[id].month << ' ' << students[id].day << endl;
    }
};


int main() {
    int studentsNumber;
    int queryNumber;
    StudentList studentList;

    string path;
    cout << "Enter the file path: ";
    cin >> path;
    ifstream input(path);
    if (input) {
        input >> studentsNumber;
        studentList.Fill(studentsNumber, input);
        input >> queryNumber;
        studentList.MakeQueries(queryNumber, input);
    }
    else {
        cout << "Error! File doesn't exists!" << endl;
    }
    return 0;
}