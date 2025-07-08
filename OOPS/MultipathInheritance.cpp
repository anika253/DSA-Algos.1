// here we use the virtual keyword to achieve runtime polymorphism.
#include <iostream>
using namespace std;
class Human{
    public:
    string name;
    void display() {
        cout << "I am a human named " << name << endl;
    }


};
class Engineer: public virtual Human {
    // Using virtual inheritance to avoid ambiguity in case of multipath inheritance
    // This allows us to ensure that there is only one instance of Human in the inheritance hierarchy
    public:
    string specialization;
    void display() {
        cout << "I am an engineer named " << name << " with specialization in " << specialization << endl;
    }
};

class Youtuber: public virtual Human {
    // Using virtual inheritance to avoid ambiguity in case of multipath inheritance
    public:
    int subscribers;
    void display() {
        cout << "I am a Youtuber named " << name << " with " << subscribers << " subscribers" << endl;
    }
};
class Coder: public Engineer, public Youtuber {
    // Coder inherits from both Engineer and Youtuber
    public:
    void display() {
        cout << "I am a Coder named " << name << ", specializing in " << specialization 
             << " with " << subscribers << " subscribers on YouTube." << endl;
    }
};                          
int main() {
    Coder c;
    c.name = "Alice";
    c.specialization = "Software Development";
    c.subscribers = 100000;

    // Displaying information using the Coder class
    c.display();

    // Displaying information using the Engineer class
    c.Engineer::display();

    // Displaying information using the Youtuber class
    c.Youtuber::display();

    return 0;
}