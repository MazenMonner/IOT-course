#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    // Private member variables
    string accountNumber;
    double balance;

public:
    // Constructor to initialize the account
    BankAccount(string accNum, double initialBalance) {
        accountNumber = accNum;
        balance = initialBalance;
    }

    // Member function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Successfully deposited $" << amount << endl;
        }
    }

    // Member function to withdraw money with logic
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds! Current balance: $" << balance << std::endl;
        } else if (amount > 0) {
            balance -= amount;
            cout << "Successfully withdrew $" << amount << endl;
        }
    }

    // Helper function to display current status
    void displayStatus() {
       cout << "Account: " << accountNumber 
                  << " | Current Balance: $" << balance << endl;
    }
};

int main() {
    // Initialize account based on example
    BankAccount myAccount("AMIT-12345", 500);

    myAccount.displayStatus();

    // Perform transactions
    myAccount.deposit(200);
    myAccount.withdraw(150);
    
    // Attempt to withdraw more than available
    myAccount.withdraw(600); 

    myAccount.displayStatus();

    return 0;
}