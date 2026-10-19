#include <iostream>
using namespace std;

class Payment {
public:
    virtual void processPayment() {
        cout << "Processing payment" << endl;
    }
};

class MobileMoney : public Payment {
public:
    void processPayment() override {
        cout << "Payment processed using Mobile Money" << endl;
    }
};

class BankCard : public Payment {
public:
    void processPayment() override {
        cout << "Payment processed using Bank Card" << endl;
    }
};

int main() {
    MobileMoney mobile;
    BankCard card;
    Payment* payment;

    payment = &mobile;
    payment->processPayment();

    payment = &card;
    payment->processPayment();

    return 0;
}
