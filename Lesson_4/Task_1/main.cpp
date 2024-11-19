#include <iostream>
#include "bank.h"

using namespace std;

int main() {
    Bank bank;

    bank.setDate(20241101);
    bank.createAccount("ACC001", 1000);
    bank.showAccountInfo("ACC001");

    bank.deposit("ACC001", 500);
    bank.showAccountInfo("ACC001");

    bank.withdraw("ACC001", 300);
    bank.showAccountInfo("ACC001");

    bank.takeCredit("ACC001", 200, 10.0);
    bank.setDate(20241115);
    bank.showAccountInfo("ACC001");

    bank.placeDeposit("ACC001", 700, 5.0);
    bank.setDate(20241119);
    bank.showAccountInfo("ACC001");

    return 0;
}
