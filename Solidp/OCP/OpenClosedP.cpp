/*
Open for Extension: You should be able to add new behavior without changing existing code.
Closed for Modification: Once a class is written and tested, you should not have to modify it to add new features.
This is the Open/Closed Principle (OCP) in object-oriented design.
Imagine a smartphone.

You can add apps to extend functionality.

You don’t open the phone’s body and change its wiring to add a calculator or calendar.

The phone is open for extension, closed for modification
u use the concept of virtual functions and inheritance to follow this principle.
*/
#include <iostream>
#include <string>

using namespace std;

class Notification {
public:
    void send(string type) {
        if (type == "email") {
            cout << "Sending Email\n";
        } else if (type == "sms") {
            cout << "Sending SMS\n";
        } else {
            cout << "Unknown notification type\n";
        }
    }
};

int main() {
    Notification n;

    n.send("email");  // Output: Sending Email
    n.send("sms");    // Output: Sending SMS
    n.send("push");   // Output: Unknown notification type

    return 0;
}
/*
This code violates the Open/Closed Principle — if you want to add a new type (like "push"), you’d need to modify the class. If you're learning SOLID principles, the better design is using polymorphism like in your earlier example.*/