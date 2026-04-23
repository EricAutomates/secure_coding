#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;     // hidden data
    double balance;        // hidden data

public:
    // Constructor
    BankAccount(int accNo, double bal) {
        accountNumber = accNo;
        balance = bal;
    }

    // Public method to deposit money
    void deposit(double amount) {
        balance += amount;
    }

    // Public method to show masked account number
    void display() {
        cout << "Account Number: ****" << accountNumber % 1000 << endl; // masking
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount acc(123456789, 5000);

    acc.deposit(2000);
    acc.display();

    return 0;
}
