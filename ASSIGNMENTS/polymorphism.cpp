#include <iostream>
#include <string>
using namespace std;

// Parent class
class Payment {
public:
    // Virtual function enables runtime polymorphism
    virtual void processPayment() {
        cout << "Processing a general payment." << endl;
    }

    virtual ~Payment() = default;
};

// Derived class 1
class MobileMoney : public Payment {
public:
    void processPayment() override {
        cout << "Processing payment using Mobile Money." << endl;
    }
};

// Derived class 2
class BankCard : public Payment {
public:
    void processPayment() override {
        cout << "Processing payment using a Bank Card." << endl;
    }
};

int main() {
    MobileMoney mobileMoney;
    BankCard bankCard;

    // A base-class pointer can point to different derived objects.
    Payment* payment;

    payment = &mobileMoney;
    payment->processPayment();

    payment = &bankCard;
    payment->processPayment();

    return 0;
}
