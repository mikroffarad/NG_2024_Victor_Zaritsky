#include <iostream>
#include "bank.h"

using namespace std;

int main() {
    Bank bank;

    bank.createAccount("ACC001", 1000);

    bank.showAccountInfo("ACC001");

    bank.deposit("ACC001", 500);

    bank.showAccountInfo("ACC001");

    bank.withdraw("ACC001", 300);

    bank.showAccountInfo("ACC001");

    return 0;
}
