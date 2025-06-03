// BankSystem.cpp
#include <iostream>
using namespace std;

// Class to represent a Bank Account
class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    // Constructor to initialize account
    BankAccount(string name, int accNum, double initialDeposit) {
        accountHolder = name;
        accountNumber = accNum;
        balance = initialDeposit;
    }

    // Method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: $" << balance << endl;
        }
        else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Method to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. Remaining balance: $" << balance << endl;
        }
        else {
            cout << "Insufficient funds or invalid amount." << endl;
        }
    }

    // Method to check balance
    void checkBalance() const {
        cout << "Current balance: $" << balance << endl;
    }

    // Method to show account details
    void showDetails() const {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        checkBalance();
    }
};

// Main program
int main() {
    string name;
    int accNumber;
    double initialDeposit;

    cout << "Welcome to the Bank Account Management System!" << endl;
    cout << "Enter your name: ";
	cin >> name;

    cout << "Choose an account number: ";
    cin >> accNumber;

    cout << "Enter initial deposit: $";
    cin >> initialDeposit;

    // Create the account
    BankAccount user(name, accNumber, initialDeposit);

    int choice;
    do {
        cout << "\n------ MENU ------" << endl;
        cout << "1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Show Account Details" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1–5): ";
        cin >> choice;

        double amount;
        switch (choice) {
        case 1:
            cout << "Enter amount to deposit: $";
            cin >> amount;
            user.deposit(amount);
            break;
        case 2:
            cout << "Enter amount to withdraw: $";
            cin >> amount;
            user.withdraw(amount);
            break;
        case 3:
            user.checkBalance();
            break;
        case 4:
            user.showDetails();
            break;
        case 5:
            cout << "Exiting... Thank you!" << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
