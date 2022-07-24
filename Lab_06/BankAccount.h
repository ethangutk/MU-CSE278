/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BankAccount.h
 * Author: cse278
 * Copyright 2020 Ethan Gutknecht
 * Created on September 30, 2020, 10:00 PM
 */

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>

class BankAccount {
public:
    BankAccount(const std::string& owner = "",
            const double balance = 0,
            const std::string& address = "");
    BankAccount(const BankAccount& orig);
    virtual ~BankAccount();
    void depositMoney(double moneyToDeposit);
    void withdrawMoney(double moneyToWithdraw);
    double getBalance();
    void updateAddress(std::string updatedAddress);
    std::string getAddress();
private:
    std::string owner;
    std::string address;
    double balance;
};

#endif /* BANKACCOUNT_H */

