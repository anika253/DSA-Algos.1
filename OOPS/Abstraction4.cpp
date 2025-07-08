
// PAYMENT METHOD EXAMPLE USING ABSTRACTION AND POLYMORPHISM IN C++
#include <iostream>
using namespace std;

// Abstract base class (Interface for payment)
class PaymentMethod {
public:
    virtual void makePayment(int amount) = 0; // Pure virtual function
    virtual ~PaymentMethod() {} // Virtual destructor
};

// Derived class for Credit Card
class CreditCard : public PaymentMethod {
public:
    void makePayment(int amount) override {
        cout << "Paid " << amount << " using Credit Card." << endl;
    }
};

// Derived class for UPI
class UPI : public PaymentMethod {
public:
    void makePayment(int amount) override {
        cout << "Paid " << amount << " using UPI." << endl;
    }
};

// Derived class for Net Banking
class NetBanking : public PaymentMethod {
public:
    void makePayment(int amount) override {
        cout << "Paid " << amount << " using Net Banking." << endl;
    }
};

// Client code (main)
int main() {
    PaymentMethod* payment;

    // Choose payment method
    payment = new CreditCard();
    payment->makePayment(1000);

    delete payment;

    payment = new UPI();
    payment->makePayment(500);

    delete payment;

    payment = new NetBanking();
    payment->makePayment(1500);

    delete payment;

    return 0;
}
