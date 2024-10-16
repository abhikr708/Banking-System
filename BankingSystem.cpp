#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Bank Account class
class BankAccount
{
private:
    string accountHolderName;
    string dateOfBirth;
    string email;
    string phoneNumber;
    string accountNumber;
    double balance;
    int pin;

public:
    BankAccount(string name, string dob, string emailId, string phone, string accNumber, double initialBalance, int initialPin)
    {
        accountHolderName = name;
        dateOfBirth = dob;
        email = emailId;
        phoneNumber = phone;
        accountNumber = accNumber;
        balance = initialBalance;
        pin = initialPin;
    }

    // Function to deposit money
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposit successful. New balance: Rs. " << balance << endl;
        }
        else
        {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Function to withdraw money (with PIN verification)
    void withdraw(double amount, int enteredPin)
    {
        if (enteredPin == pin)
        {
            if (amount > 0 && amount <= balance)
            {
                balance -= amount;
                cout << "Withdrawal successful. New balance: Rs. " << balance << endl;
            }
            else
            {
                cout << "Invalid withdrawal amount or insufficient balance." << endl;
            }
        }
        else
        {
            cout << "Incorrect PIN!" << endl;
        }
    }

    // Function to display account information (with PIN verification)
    void displayAccountInfo(int enteredPin)
    {
        if (enteredPin == pin)
        {
            cout << "Account Holder: " << accountHolderName << endl;
            cout << "Date of Birth: " << dateOfBirth << endl;
            cout << "Email: " << email << endl;
            cout << "Phone Number: " << phoneNumber << endl;
            cout << "Account Number: " << accountNumber << endl;
            cout << "Balance: Rs. " << balance << endl;
        }
        else
        {
            cout << "Incorrect PIN!" << endl;
        }
    }

    // Function to change the PIN
    void changePin(int oldPin, int newPin)
    {
        if (oldPin == pin)
        {
            pin = newPin;
            cout << "PIN changed successfully!" << endl;
        }
        else
        {
            cout << "Incorrect current PIN!" << endl;
        }
    }

    // Function to edit account holder details
    void editUserDetails()
    {
        cout << "Enter new account holder's name: ";
        cin.ignore();
        getline(cin, accountHolderName);
        cout << "Enter new date of birth (DD/MM/YYYY): ";
        getline(cin, dateOfBirth);
        cout << "Enter new email ID: ";
        getline(cin, email);
        cout << "Enter new phone number: ";
        getline(cin, phoneNumber);
        cout << "Enter new account number: ";
        getline(cin, accountNumber);
        cout << "Account details updated successfully!" << endl;
    }

    // Function to get account number
    string getAccountNumber() 
    {
        return accountNumber;
    }

    // Function to get account holder name
    string getAccountHolderName() 
    {
        return accountHolderName;
    }
};

// Main function
int main()
{
    vector<BankAccount> accounts;

    // Customer functionality
    int choice;
    do
    {
        cout << "\n----- Customer Menu -----\n";
        cout << "1. Create New Bank Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Display Account Info\n";
        cout << "5. Change PIN\n";
        cout << "6. Edit Account Details\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name, dob, email, phone, accNumber;
            double initialBalance;
            int pin;

            cout << "Enter account holder's name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter date of birth (DD/MM/YYYY): ";
            getline(cin, dob);
            cout << "Enter email ID: ";
            getline(cin, email);
            cout << "Enter phone number: ";
            getline(cin, phone);
            cout << "Enter account number: ";
            getline(cin, accNumber);
            cout << "Enter initial balance: ";
            cin >> initialBalance;
            cout << "Set a security PIN (Numbers only): ";
            cin >> pin;

            accounts.push_back(BankAccount(name, dob, email, phone, accNumber, initialBalance, pin));
            cout << "Account created successfully!\n";
            break;
        }
        case 2:
        {
            string accNumber;
            double amount;
            int enteredPin;

            cout << "Enter account number: ";
            cin.ignore();
            getline(cin, accNumber);
            cout << "Enter amount to deposit: ";
            cin >> amount;

            for (auto &account : accounts)
            {
                if (account.getAccountNumber() == accNumber) // Check account number instead of name
                {
                    account.deposit(amount);
                    break;
                }
            }
            break;
        }
        case 3:
        {
            string accNumber;
            double amount;
            int enteredPin;

            cout << "Enter account number: ";
            cin.ignore();
            getline(cin, accNumber);
            cout << "Enter your PIN: ";
            cin >> enteredPin;
            cout << "Enter amount to withdraw: ";
            cin >> amount;

            for (auto &account : accounts)
            {
                if (account.getAccountNumber() == accNumber) // Check account number instead of name
                {
                    account.withdraw(amount, enteredPin);
                    break;
                }
            }
            break;
        }
        case 4:
        {
            string accNumber;
            int enteredPin;

            cout << "Enter account number: ";
            cin.ignore();
            getline(cin, accNumber);
            cout << "Enter your PIN: ";
            cin >> enteredPin;

            for (auto &account : accounts)
            {
                if (account.getAccountNumber() == accNumber) // Check account number instead of name
                {
                    account.displayAccountInfo(enteredPin);
                    break;
                }
            }
            break;
        }
        case 5:
        {
            string accNumber;
            int oldPin, newPin;

            cout << "Enter account number: ";
            cin.ignore();
            getline(cin, accNumber);
            cout << "Enter current PIN: ";
            cin >> oldPin;
            cout << "Enter new PIN: ";
            cin >> newPin;

            for (auto &account : accounts)
            {
                if (account.getAccountNumber() == accNumber) // Check account number instead of name
                {
                    account.changePin(oldPin, newPin);
                    break;
                }
            }
            break;
        }
        case 6:
        {
            string accNumber;

            cout << "Enter account number: ";
            cin.ignore();
            getline(cin, accNumber);

            for (auto &account : accounts)
            {
                if (account.getAccountNumber() == accNumber) // Check account number instead of name
                {
                    account.editUserDetails();
                    break;
                }
            }
            break;
        }
        case 7:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
