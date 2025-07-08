/*
ABSTRACTION can be implemted using abstract classes or interfaces in C++.
abstract class is a class that contains at least one pure virtual function.
Interfaces are a way to achieve abstraction in C++ by defining a class with all fnxns as pure virtual functions.
*/
/* ABSTRACTION USING PURE VIRTUAL FNXN : ABSTRACT CLASSES*/
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
    void speak() override{ // override is optional but it is a good practice to use it
        cout << "Derived speaking"<< endl;
    }
};

int main() {
	Base*a= new Derived;
	a->speak();

}
