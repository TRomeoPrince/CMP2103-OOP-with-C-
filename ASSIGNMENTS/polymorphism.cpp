#include <iostream>
using namespace std;

// Polymorphism: the same function call can behave differently
// depending on the actual object being used.

// Payment is the parent (base) class.
class Payment {
public:
    // virtual tells C++ to use the function belonging to the
    // actual object at runtime, even through a Payment pointer.
    virtual void processPayment() {
        cout << "Processing payment" << endl;
    }
};

// MobileMoney inherits from Payment.
class MobileMoney : public Payment {
public:
    // override means we are replacing the parent's virtual function.
    void processPayment() override {
        cout << "Payment processed using Mobile Money" << endl;
    }
};

// BankCard is another child of Payment.
class BankCard : public Payment {
public:
    // The same function name produces a different result for card payments.
    void processPayment() override {
        cout << "Payment processed using Bank Card" << endl;
    }
};

int main() {
    // Create one object of each child class.
    MobileMoney mobile;
    BankCard card;

    // A base-class pointer can point to objects of derived classes.
    Payment* payment;

    // Point to MobileMoney: the virtual call uses MobileMoney's version.
    payment = &mobile;
    payment->processPayment();

    // Reuse the SAME pointer and function call with a BankCard object.
    payment = &card;
    payment->processPayment();

    // Notice: payment->processPayment() did not change,
    // but its output changed. That is runtime polymorphism.
    return 0;
}
