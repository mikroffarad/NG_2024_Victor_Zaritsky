#ifndef BANK_H
#define BANK_H

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

        AccountInfo();
    };

    map<string, AccountInfo> accounts;
    int currentDate;

    void calculateInterest(AccountInfo &account, int days);

public:
    Bank();
    void setDate(int newDate);
    bool createAccount(string accountID, float initialBalance);
    bool deleteAccount(string accountID);
    void showAccountInfo(string accountID);
    bool deposit(string accountID, float amount);
    bool withdraw(string accountID, float amount);
    bool takeCredit(string accountID, float amount, float annualInterestRate);
    bool returnCredit(string accountID, float amount);
    bool placeDeposit(string accountID, float amount, float annualInterestRate);
    bool withdrawDeposit(string accountID, float amount);
};

#endif // BANK_H
