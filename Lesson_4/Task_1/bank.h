#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Bank {
private:
    struct AccountInfo {
        float balance;
        float credit;
        float deposit;
        int depositDate;
        int creditDate;
        float depositRate;
        float creditRate;

        AccountInfo()
            : balance(0), credit(0), deposit(0), depositDate(0), creditDate(0), depositRate(0), creditRate(0) {}
    };

    map<string, AccountInfo> accounts;
    int currentDate; // Stores the current date as an integer (e.g., YYYYMMDD)

    void calculateInterest(AccountInfo &account, int days) {
        if (account.deposit > 0 && account.depositDate > 0) {
            account.balance += account.deposit * (account.depositRate / 365) * days;
        }
        if (account.credit > 0 && account.creditDate > 0) {
            account.credit += account.credit * (account.creditRate / 365) * days;
        }
    }

public:
    Bank() : currentDate(0) {}

    void setDate(int newDate) {
        if (newDate <= currentDate) {
            cout << "Invalid date. The new date must be in the future." << endl;
            return;
        }
        int daysPassed = newDate - currentDate;
        for (auto &entry : accounts) {
            calculateInterest(entry.second, daysPassed);
        }
        currentDate = newDate;
    }

    bool createAccount(string accountID, float initialBalance) {
        if (accounts.find(accountID) == accounts.end()) {
            accounts[accountID].balance = initialBalance;
            return true;
        }
        return false;
    }

    bool deleteAccount(string accountID) {
        return accounts.erase(accountID) > 0;
    }

    void showAccountInfo(string accountID) {
        auto it = accounts.find(accountID);
        if (it != accounts.end()) {
            AccountInfo &info = it->second;
            cout << "Account ID: " << accountID << endl
                 << "Balance: " << info.balance << endl
                 << "Credit: " << info.credit << endl
                 << "Deposit: " << info.deposit << endl
                 << "Current Date: " << currentDate << endl;
        } else {
            cout << "Account not found!" << endl;
        }
    }

    bool deposit(string accountID, float amount) {
        if (amount <= 0) return false;

        auto it = accounts.find(accountID);
        if (it != accounts.end()) {
            it->second.balance += amount;
            return true;
        }
        return false;
    }

    bool withdraw(string accountID, float amount) {
        if (amount <= 0) return false;

        auto it = accounts.find(accountID);
        if (it != accounts.end() && it->second.balance >= amount) {
            it->second.balance -= amount;
            return true;
        }
        return false;
    }

    bool takeCredit(string accountID, float amount, float annualInterestRate) {
        if (amount <= 0 || annualInterestRate <= 0) return false;

        auto it = accounts.find(accountID);
        if (it != accounts.end()) {
            it->second.credit += amount;
            it->second.creditDate = currentDate;
            it->second.balance += amount;
            it->second.creditRate = annualInterestRate / 100;
            return true;
        }
        return false;
    }

    bool returnCredit(string accountID, float amount) {
        if (amount <= 0) return false;

        auto it = accounts.find(accountID);
        if (it != accounts.end() && it->second.credit >= amount) {
            it->second.credit -= amount;
            it->second.balance -= amount;
            return true;
        }
        return false;
    }

    bool placeDeposit(string accountID, float amount, float annualInterestRate) {
        if (amount <= 0 || annualInterestRate <= 0) return false;

        auto it = accounts.find(accountID);
        if (it != accounts.end() && it->second.balance >= amount) {
            it->second.deposit += amount;
            it->second.depositDate = currentDate;
            it->second.balance -= amount;
            it->second.depositRate = annualInterestRate / 100;
            return true;
        }
        return false;
    }

    bool withdrawDeposit(string accountID, float amount) {
        if (amount <= 0) return false;

        auto it = accounts.find(accountID);
        if (it != accounts.end() && it->second.deposit >= amount) {
            it->second.deposit -= amount;
            it->second.balance += amount;
            return true;
        }
        return false;
    }
};

#endif // BANK_H
