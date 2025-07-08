#include <iostream>
using namespace std;
class Engineer{
    public:
    string  specialisation;
    void money(){
        cout << "I am an engineer and I earn Rs 200000 monthly!" << endl;
    }
Engineer()
{
    cout << "I am an engineer!" << endl;
}
      void work()
      {
        cout << "i have specialisation in " << specialisation << endl;
      }

};
class Youtuber{
    public:
    int subscribers;
    Youtuber()
    {
        cout << "I am a Youtuber!" << endl;
    }
    void contentCreator()
    {
        cout << "I have " << subscribers << " subscribers!" << endl;
    }

};
class Coder: public Engineer, public Youtuber{
    public:
    string name;
    
    Coder()
    {
        cout << "I am a Coder!" << endl;
    }
   Coder(string n, string spec, int sub)
    {
        name = n;
        specialisation = spec;
        subscribers = sub;
    }
    void introduce()
    {
        cout << "Hello, I am " << name << ", a Coder!" << endl;
        work();
        contentCreator();
    }
};  

int main() {
    Coder c("Tom"," Development", 100000);
    c.introduce();
    c.money();
    return 0;
}
// This code demonstrates multiple inheritance in C++ where the Coder class inherits from both Engineer and  Youtuber classes.
// The Coder class can access members from both base classes, allowing it to combine functionalities from       