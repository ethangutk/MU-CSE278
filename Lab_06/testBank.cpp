// Copyright 2020 Christopher Vendome
#include <iostream>
#include <fstream>
#include <string>
#include "BankAccount.h"

int main() {
    BankAccount testAccount1("John Doe", 4000.00, "Main Street");
    testAccount1.depositMoney(3000);
    testAccount1.withdrawMoney(1000);
    testAccount1.updateAddress("Alternative Street");

    std::cout << "Test 1: " << testAccount1.getBalance() << " "
           << testAccount1.getAddress() << std::endl;

    BankAccount testAccount2("Jane Doe", 15000.00, "Main Drive");
    testAccount2.depositMoney(21000.00);
    testAccount2.withdrawMoney(5000.00);
    testAccount2.updateAddress("Miami Place");

    std::cout << "Test 2: " << testAccount2.getBalance() << " "
           << testAccount2.getAddress() << std::endl;

    BankAccount testAccount3("Bob", 1000.98, "Orange Grove");
    testAccount3.depositMoney(15.99);
    testAccount3.withdrawMoney(21.32);
    testAccount3.updateAddress("Peach Grove");

    std::cout << "Test 3: " << testAccount3.getBalance() << " "
           << testAccount3.getAddress() << std::endl;

    return 0;
}
