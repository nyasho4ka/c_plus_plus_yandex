#include <iostream>
#include "phone_number.h"


int main() {
    PhoneNumber phone_number1 = PhoneNumber("+7-999-133-87-76");
    cout << phone_number1.GetInternationalNumber() << endl;
    PhoneNumber phone_number2 = PhoneNumber("+7-495-111-22-33");
    cout << phone_number2.GetInternationalNumber() << endl;
    PhoneNumber phone_number3 = PhoneNumber("+7-495-1112233");
    cout << phone_number3.GetInternationalNumber() << endl;
    PhoneNumber phone_number4 = PhoneNumber("+323-22-460002");
    cout << phone_number4.GetInternationalNumber() << endl;
    PhoneNumber phone_number5 = PhoneNumber("+1-2-coursera-cpp");
    cout << phone_number5.GetInternationalNumber() << endl;
    try {
        PhoneNumber phone_number6 = PhoneNumber("1-2-333");
        cout << phone_number6.GetInternationalNumber() << endl;
    } catch(exception& e) {
        cout << "WRONG NUMBER FORMAT " << e.what() << endl;
    }
    try {
        PhoneNumber phone_number6 = PhoneNumber("+7-1233");
        cout << phone_number6.GetInternationalNumber() << endl;
    } catch(exception& e) {
        cout << "WRONG NUMBER FORMAT " << e.what() << endl;
    }
    try {
        PhoneNumber phone_number6 = PhoneNumber("+");
        cout << phone_number6.GetInternationalNumber() << endl;
    } catch(exception& e) {
        cout << "WRONG NUMBER FORMAT " << e.what() << endl;
    }
    try {
        PhoneNumber phone_number6 = PhoneNumber("+--");
        cout << phone_number6.GetInternationalNumber() << endl;
    } catch(exception& e) {
        cout << "WRONG NUMBER FORMAT " << e.what() << endl;
    }
    try {
        PhoneNumber phone_number6 = PhoneNumber("+0---");
        cout << phone_number6.GetInternationalNumber() << endl;
    } catch(exception& e) {
        cout << "WRONG NUMBER FORMAT " << e.what() << endl;
    }
}
