#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string holderName;
    double balance;
    double minBalance;

public:
    // Constructor
    BankAccount(int accNo, string name, double bal) {
        accountNumber = accNo;
        holderName = name;
        balance = bal;
        minBalance = 500; // minimum balance rule
    }

    // Deposit function
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    // Withdraw function
    void withdraw(double amount) {
        if (balance - amount < minBalance) {
            cout << "Withdrawal failed! Minimum balance rule violated.\n";
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }

    // Display balance
    void displayBalance() {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nHolder Name: " << holderName;
        cout << "\nCurrent Balance: " << balance << endl;
    }
};

int main() {
    int accNo;
    string name;
    double bal;

    cout << "Enter Account Number: ";
    cin >> accNo;
    cout << "Enter Holder Name: ";
    cin >> name;
    cout << "Enter Initial Balance: ";
    cin >> bal;

    BankAccount acc(accNo, name, bal);

    int choice;
    double amount;

    do {
        cout << "\n--- BANK MENU ---\n";
        cout << "1. Deposit\n2. Withdraw\n3. Display Balance\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter amount: ";
                cin >> amount;
                acc.deposit(amount);
                break;

            case 2:
                cout << "Enter amount: ";
                cin >> amount;
                acc.withdraw(amount);
                break;

            case 3:
                acc.displayBalance();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 4);

    return 0;
}
