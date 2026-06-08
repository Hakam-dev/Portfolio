/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BankAccount {
private:
    string name;
    int accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(string n, int accNum, double bal) {
        name = n;
        accountNumber = accNum;
        balance = bal;
    }

    // Deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance = balance + amount;
            cout << "Money deposited successfully!" << endl;
            cout << "New balance: " << balance << endl;
        } else {
            cout << "Please enter a positive amount!" << endl;
        }
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance = balance - amount;
            cout << "Money withdrawn successfully!" << endl;
            cout << "New balance: " << balance << endl;
        } else {
            cout << "Not enough money or invalid amount!" << endl;
        }
    }

    // Show account details
    void showAccount() {
        cout << "\n--- Account Info ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "-------------------" << endl;
    }

    // Get account number
    int getAccountNumber() {
        return accountNumber;
    }
};

int main() {
    vector<BankAccount> accounts;
    int choice;

    cout << "Welcome to Simple Bank!" << endl;

    while (true) {
        cout << "\n1. Create Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Show Account" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose (1-5): ";
        cin >> choice;

        if (choice == 1) {
            // Create account
            string name;
            int accNum;
            double startMoney;
            
            cout << "Enter your name: ";
            cin >> name;
            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter starting money: ";
            cin >> startMoney;
            
            BankAccount newAccount(name, accNum, startMoney);
            accounts.push_back(newAccount);
            cout << "Account created!" << endl;
        }
        else if (choice == 2) {
            // Deposit
            int accNum;
            double money;
            
            cout << "Enter account number: ";
            cin >> accNum;
            
            // Find account
            bool found = false;
            for (int i = 0; i < accounts.size(); i++) {
                if (accounts[i].getAccountNumber() == accNum) {
                    cout << "Enter money to deposit: ";
                    cin >> money;
                    accounts[i].deposit(money);
                    found = true;
                    break;
                }
            }
            
            if (!found) {
                cout << "Account not found!" << endl;
            }
        }
        else if (choice == 3) {
            // Withdraw
            int accNum;
            double money;
            
            cout << "Enter account number: ";
            cin >> accNum;
            
            // Find account
            bool found = false;
            for (int i = 0; i < accounts.size(); i++) {
                if (accounts[i].getAccountNumber() == accNum) {
                    cout << "Enter money to withdraw: ";
                    cin >> money;
                    accounts[i].withdraw(money);
                    found = true;
                    break;
                }
            }
            
            if (!found) {
                cout << "Account not found!" << endl;
            }
        }
        else if (choice == 4) {
            // Show account
            int accNum;
            
            cout << "Enter account number: ";
            cin >> accNum;
            
            // Find account
            bool found = false;
            for (int i = 0; i < accounts.size(); i++) {
                if (accounts[i].getAccountNumber() == accNum) {
                    accounts[i].showAccount();
                    found = true;
                    break;
                }
            }
            
            if (!found) {
                cout << "Account not found!" << endl;
            }
        }
        else if (choice == 5) {
            cout << "Thank you! Goodbye!" << endl;
            break;
        }
        else {
            cout << "Wrong choice! Try again." << endl;
        }
    }

    return 0;
}
*/



#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BankAccount {
private:
    string name;
    int accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(string n, int accNum, double bal) {
        name = n;
        accountNumber = accNum;
        balance = bal;
    }

    // Deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Money deposited successfully!" << endl;
            cout << "New balance: " << balance << endl;
        } else {
            cout << "Please enter a positive amount!" << endl;
        }
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Money withdrawn successfully!" << endl;
            cout << "New balance: " << balance << endl;
        } else {
            cout << "Not enough money or invalid amount!" << endl;
        }
    }

    // Loan feature (added from second code)
    void takeLoan(double amount, int months) {
        if (amount > balance * 0.7) {
            cout << "Loan request denied: You are only eligible to borrow up to 70% of your account due to our Policy. ($"
                 << balance * 0.7 << ").\n";
            return;
        }

        if (amount > 0 && months >= 1 && months <= 12) {
            double interestRate = 0.10; // 10% per month
            double totalRepayment = amount * (1 + interestRate * months);
            balance += amount;
            cout << "Loan approved!\n";
            cout << "Loan amount credited: $" << amount << endl;
            cout << "Repayment duration: " << months << " month(s)" << endl;
            cout << "Total repayment after " << months << " months: $" << totalRepayment << endl;
            cout << "New account balance: $" << balance << endl;
        } else {
            cout << "Invalid loan amount or duration (must be within 1-12 months).\n";
        }
    }

    // Show account details
    void showAccount() {
        cout << "\n--- Account Info ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "-------------------" << endl;
    }

    // Get account number
    int getAccountNumber() {
        return accountNumber;
    }
};

int main() {
    vector<BankAccount> accounts;
    int choice;

    cout << "Welcome to Simple Bank!" << endl;

    while (true) {
        cout << "\n1. Create Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Show Account" << endl;
        cout << "5. Take Loan" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose (1-6): ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int accNum;
            double startMoney;

            cin.ignore();
            cout << "Enter your name: ";
            getline(cin, name);
            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter starting money: ";
            cin >> startMoney;

            BankAccount newAccount(name, accNum, startMoney);
            accounts.push_back(newAccount);
            cout << "Account created!" << endl;
        }
        else if (choice == 2) {
            int accNum;
            double money;

            cout << "Enter account number: ";
            cin >> accNum;

            bool found = false;
            for (int i = 0; i < accounts.size(); i++) {
                if (accounts[i].getAccountNumber() == accNum) {
                    cout << "Enter money to deposit: ";
                    cin >> money;
                    accounts[i].deposit(money);
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Account not found!" << endl;
            }
        }
        else if (choice == 3) {
            int accNum;
            double money;

            cout << "Enter account number: ";
            cin >> accNum;

            bool found = false;
            for (int i = 0; i < accounts.size(); i++) {
                if (accounts[i].getAccountNumber() == accNum) {
                    cout << "Enter money to withdraw: ";
                    cin >> money;
                    accounts[i].withdraw(money);
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Account not found!" << endl;
            }
        }
        else if (choice == 4) {
            int accNum;

            cout << "Enter account number: ";
            cin >> accNum;

            bool found = false;
            for (int i = 0; i < accounts.size(); i++) {
                if (accounts[i].getAccountNumber() == accNum) {
                    accounts[i].showAccount();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Account not found!" << endl;
            }
        }
        else if (choice == 5) {
            int accNum, months;
            double amount;

            cout << "Enter account number: ";
            cin >> accNum;

            bool found = false;
            for (int i = 0; i < accounts.size(); i++) {
                if (accounts[i].getAccountNumber() == accNum) {
                    cout << "Enter loan amount: ";
                    cin >> amount;
                    cout << "Enter loan duration in months (1 to 12): ";
                    cin >> months;
                    accounts[i].takeLoan(amount, months);
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Account not found!" << endl;
            }
        }
        else if (choice == 6) {
            cout << "Thank you! Goodbye!" << endl;
            break;
        }
        else {
            cout << "Wrong choice! Try again." << endl;
        }
    }

    return 0;
}

