// POLYMORPHISM1.CPP

// 2 TYPES OF POLYMORPHISM :COMPILE TIME AND RUNTIME
// COMPILE TIME POLYMORPHISM: FUNCTION OVERLOADING AND OPERATOR OVERLOADING
// RUNTIME POLYMORPHISM: VIRTUAL FUNCTIONS

/*____________________________FUNCTIONOVERLOADING_______________________________*/

#include <iostream>
#include <string>
using namespace std;
class Print{
    public:
    void show(int a)
    {
        cout << "our integer is"<< a<< endl;
    }
    void show(string s)
    {
        cout << "our string is"<< s<< endl;
    }
};

int main() {
	Print p;
	p.show(10);
	p.show("tom");

}
