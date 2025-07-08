// what happens wiithout override keyword in C++?..it will call base class fucntion which is not a good practice
//if we have used the kwyword virtual here.
// also i have changed function name from speak to Speak in the derived class to  not match the base class function name.

#include <iostream>   
#include <string>                                                              
using namespace std;
class Base{
    public:
    virtual void speak()
    {
        cout << "base speaking"<< endl;
    }
};
class Derived: public Base{
    public :
    void Speak() { // override is optional but it is a good practice to use it
        cout << "Derived speaking"<< endl;
    }
};

int main() {
	Base*a= new Derived;
	a->speak();

}
