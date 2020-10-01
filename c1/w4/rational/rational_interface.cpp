#include <iostream>
#include <numeric>
using namespace std;


class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
        numerator = 0;
        denominator = 1;
    }

    Rational(int new_numerator, int new_denominator) {
        // Реализуйте конструктор
        if (new_denominator < 0) {
            new_numerator *= -1;
            new_denominator *= -1;
        }
        int nod = gcd(new_numerator, new_denominator);
        numerator = new_numerator / nod;
        denominator = new_denominator / nod;
    }

    int Numerator() const {
        // Реализуйте этот метод
        return numerator;
    }

    int Denominator() const {
        // Реализуйте этот метод
        return denominator;
    }

    bool operator==(const Rational& other) {
        return other.Numerator() == numerator and other.Denominator() == denominator;
    }

    Rational operator+(const Rational& other) {
        return Rational(numerator + other.Numerator(), denominator + other.Denominator());
    }

    Rational operator-(const Rational& other) {
        return Rational(numerator - other.Numerator(), denominator - other.Denominator());
    }

private:
    // Добавьте поля
    int numerator, denominator;
};

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    cout << "OK" << endl;
    return 0;
}
