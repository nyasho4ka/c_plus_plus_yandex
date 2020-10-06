#include <numeric>
#include <iostream>
using namespace std;

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int new_numerator, int new_denominator) {
        if (new_denominator == 0) {
            throw invalid_argument("Denominator equals to zero!");
        }
        if (new_denominator < 0) {
                new_numerator *= -1;
                new_denominator *= -1;
            }
            SetValues(new_numerator, new_denominator);
        }

    void SetValues(int new_numerator, int new_denominator) {
        int nod = gcd(new_numerator, new_denominator);
        numerator = new_numerator / nod;
        denominator = new_denominator / nod;
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

    Rational operator/(const Rational& other) {
        if (other.Numerator() == 0) {
            throw domain_error("Numerator is equal to zero!");
        }
        return Rational(numerator * other.Denominator(), denominator * other.Numerator());
    }
private:
    int numerator, denominator;
};

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}