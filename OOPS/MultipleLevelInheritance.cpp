#include <iostream>
using namespace std;
class Person{
protected: string name;
public:
void intoduce(){
    cout << "Hello, my name is " << name << endl;
}
};
class Employee: public Person{
    protected: int salary;
    public:
    void monthlySalary(){
        cout << "My monthly salary is " << salary << endl;
    }
};
class Manager: public Employee{
    protected: string department;
    public:
    Manager(string n, int s, string d) {
        name = n;
        salary = s;
        department = d;
    }
    void manage(){
        cout << "I manage the " << department << " department." << endl;
    }
};
int main()
{
    Manager m("Tom", 5000, "HR");
   m.intoduce();
    m.monthlySalary();
    m.manage();
    return 0;
}