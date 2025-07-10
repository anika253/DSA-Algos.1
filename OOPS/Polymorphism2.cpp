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


Common Operators You Can Overload
Operator	Symbol	Common Use
Arithmetic	+, -, *, /, %	Vector math, big integers
Assignment	=	Deep copy of objects
Comparison	==, !=, <, >, <=, >=	Sorting, searching
Stream	<<, >>	Printing (cout), input
Subscript	[]	Custom container indexing
Function call	()	Functor objects
Dereference	*, ->	Smart pointers
Increment/Decrement	++, --	Iterators
Logical	!, &&, `


Real-life Use Cases
std::string overloads + for concatenation

std::vector overloads [] for indexing

std::cout overloads <<

 Why Use It?
Makes your classes behave more like built-in types

Improves readability

Simplifies code using custom objects
// Allows intuitive operations like addition, comparison, etc.





*/