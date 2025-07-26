#include <iostream>
using namespace std;

// Interface / Abstract Base Class
class INotification {
public:
    virtual void send() = 0;
    virtual ~INotification() = default;
};

// Concrete implementation: Email
class EmailNotification : public INotification {
public:
    void send() override {
        cout << "Sending Email\n";
    }
};

// Concrete implementation: SMS
class SMSNotification : public INotification {
public:
    void send() override {
        cout << "Sending SMS\n";
    }
};

// Concrete implementation: Push
class PushNotification : public INotification {
public:
    void send() override {
        cout << "Sending Push Notification\n";
    }
};

// Common notifier function
void notifyUser(INotification* notification) {
    notification->send();
}

// Main function
int main() {
    EmailNotification email;
    SMSNotification sms;
    PushNotification push;

    notifyUser(&email);  // Output: Sending Email
    notifyUser(&sms);    // Output: Sending SMS
    notifyUser(&push);   // Output: Sending Push Notification

    return 0;
}
