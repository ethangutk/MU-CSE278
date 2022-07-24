/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BankAccount.cpp
 * Author: cse278
 * Copyright 2020 Ethan Gutknecht
 * Created on September 30, 2020, 10:00 PM
 */

#include "BankAccount.h"

BankAccount::BankAccount(const std::string& owner,
            const double balance,
            const std::string& address) {
    this->owner = owner;
    this->balance = balance;
    this->address = address;
}

BankAccount::BankAccount(const BankAccount& orig) {
}

BankAccount::~BankAccount() {
}


void BankAccount::depositMoney(double moneyToDeposit) {
    this->balance += moneyToDeposit;
}


void BankAccount::withdrawMoney(double moneyToWithdraw) {
    this->balance -= moneyToWithdraw;
}


double BankAccount::getBalance() {
    return this->balance;
}


void BankAccount::updateAddress(std::string updatedAddress) {
    this->address = updatedAddress;
}

std::string BankAccount::getAddress() {
    return this->address;
}


