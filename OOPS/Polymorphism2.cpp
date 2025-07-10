//________________OPERATOR OVERLOADING____________________
#include <iostream>
using namespace std;

class Complex {
public:
    int real, imag;

    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    // Overload + operator
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload << operator for printing
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }
};

int main() {
    Complex c1(3, 4), c2(1, 2);
    Complex c3 = c1 + c2;

    cout << "Result: " << c3 << endl;  // 4 + 6i
    return 0;
}
/*
Some operators cannot be overloaded, like:

:: (scope resolution)

. (member access)

.* (pointer-to-member access)

sizeof, typeid











*/