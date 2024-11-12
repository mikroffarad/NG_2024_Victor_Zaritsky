#ifndef BANK_H
#define BANK_H

#endif // BANK_H

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Bank {
private:
    struct accountInfo {
        float balance;
        float credit;
        float deposit;

        accountInfo() : balance(0), credit(0), deposit(0) {}
    };

    map<string, accountInfo> accounts;

    int currentDate;

public:
    Bank() : currentDate(0) {}

    bool createAccount(string accountID, float initialBalance) {
        if (accounts.find(accountID) == accounts.end()) {
            accounts[accountID].balance = initialBalance;
            return true; // Account created successfully
        }
        return false; // Account already created
    }

    bool deleteAccount(string accountID) {
        return accounts.erase(accountID) > 0;
    }

    void showAccountInfo(string accountID) {
        auto it = accounts.find(accountID);
        if (it != accounts.end()) {
            accountInfo info = it->second;
            cout << "Account ID: " << accountID << endl
                 << "Balance: " << info.balance << endl
                 << "Credit: " << info.credit << endl
                 << "Deposit: " << info.credit << endl;
        } else {
            cout << "Account not found!" << endl;
        }
    }

    bool deposit(string accountID, float amount) {
        if (amount <= 0) {
            return false;
        }

        auto it = accounts.find(accountID);
        if (it != accounts.end()) {
            it->second.balance += amount;
            return true;
        }
        return false;
    }

    bool withdraw(string accountID, float amount) {
        if (amount <= 0) {
            return false;
        }

        auto it = accounts.find(accountID);
        if (it != accounts.end()) {
            it->second.balance -= amount;
            return true;
        }
        return false;
    }

};
