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
/*class Derived: public Base{
    public :
    void Speak() override{ // override is optional but it is a good practice to use it
        cout << "Derived speaking"<< endl;
    }
};

int main() {
	Base*a= new Derived;
	a->speak();

}
*/
// So here if we have not used the override keyword then it will call the derived class function only which i have mistakenly written as Speak instead of speak.
// so it will give error that is correct bcs i have used virtual keyword here and i expect to run the derived class function only 
