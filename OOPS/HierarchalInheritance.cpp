#include <iostream>
using namespace std;

// Base class
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    void introduce() {
        cout << "Hi, I'm " << name << " and I'm " << age << " years old." << endl;
    }
};

// Derived class 1
class Student : public Person {
private:
    int rollNumber;

public:
    Student(string n, int a, int roll) : Person(n, a) {
        rollNumber = roll;
    }

    void study() {
        cout << name << " is studying. Roll No: " << rollNumber << endl;
    }
};

// Derived class 2
class Teacher : public Person {
private:
    string subject;

public:
    Teacher(string n, int a, string sub) : Person(n, a) {
        subject = sub;
    }

    void teach() {
        cout << name << " is teaching " << subject << "." << endl;
    }
};

int main() {
    Student s1("A", 20, 101);
    Teacher t1("Mr. Kr", 40, "Math");

    cout << "Student Details:" << endl;
    s1.introduce();
    s1.study();

    cout << "\nTeacher Details:" << endl;
    t1.introduce();
    t1.teach();

    return 0;
}
