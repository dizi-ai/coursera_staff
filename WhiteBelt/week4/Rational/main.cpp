#include <iostream>
#include <numeric>
#include <stdexcept>
class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }
    Rational(int new_numerator, int new_denominator) {
        if (new_denominator!=0) {
            const int gcd = std::gcd(new_numerator, new_denominator);
            numerator = new_numerator / gcd;
            denominator = new_denominator / gcd;
            if (denominator < 0) {
                denominator = -denominator;
                numerator = -numerator;
            }
        }
        else {
            throw std::invalid_argument("Invalid argument");
        }
    }
    int Numerator() const {
        return numerator;
    }
    int Denominator() const {
        return denominator;
    }
private:
    int numerator;
    int denominator;
};
bool operator == (const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() &&
           lhs.Denominator() == rhs.Denominator();
}
Rational operator + (const Rational& lhs, const Rational& rhs) {
    return {
            lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
            lhs.Denominator() * rhs.Denominator()
    };
}
Rational operator - (const Rational& lhs, const Rational& rhs) {
    return {
            lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
            lhs.Denominator() * rhs.Denominator()
    };
}
Rational operator * (const Rational& lhs, const Rational& rhs) {
    return {
            lhs.Numerator() * rhs.Numerator(),
            lhs.Denominator() * rhs.Denominator()
    };
}
Rational operator / (const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator()==0){
        throw std::domain_error("Division by zero");
    }
    else {
        return lhs * Rational(rhs.Denominator(), rhs.Numerator());
    }
}
std::istream& operator >> (std::istream& is, Rational& r) {
    int n, d;
    char c;

    if (is) {
        is >> n >> c >> d;
        if (is && c == '/') {
            r = Rational(n, d);
        }
    }
    return is;
}
std::ostream& operator << (std::ostream& os, const Rational& r) {
    return os << r.Numerator() << '/' << r.Denominator();
}
bool operator < (const Rational& lhs, const Rational& rhs) {
    return (lhs - rhs).Numerator() < 0;
}
int main() {
    Rational r1;
    Rational r2;
    char operation ;
    try {
        std::cin >> r1 >> operation >> r2;
        if (operation=='+'){
            std::cout << r1 + r2 << std::endl;
        }
        else if (operation=='-'){
            std::cout << r1 - r2 << std::endl;
        }
        else if (operation=='*'){
            std::cout << r1 * r2 << std::endl;
        }
        else if (operation=='/'){
            try {
                std::cout << r1 / r2 << std::endl;
            }
            catch (std::domain_error&de) {
                std::cout << "Division by zero"<<std::endl;

            }
        }
    }
    catch (std::invalid_argument&inv) {
        std::cout << "Invalid argument"<<std::endl;
    }

}