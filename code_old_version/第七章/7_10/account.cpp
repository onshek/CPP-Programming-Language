//
// Created by honfu on 2020/3/22.
//

#include "account.h"
#include <cmath>
#include <iostream>

using namespace std;

double Account::total = 0;

Account::Account(const Date &date, const string &id) : id(id), balance(0) {
    date.show();
    cout << "\t# " << id << " created" << endl;
}

void Account::record(const Date &date, double amount, const std::string &desc) {
    amount = floor(amount * 100 + 0.5) / 100;
    balance += amount;
    total += amount;
    date.show();
    cout << "\t# " << id << "\t " << amount << "\t" << balance << "\t" << desc << endl;
}

void Account::show() const { cout << id << "\tBa1ance: " << balance; }

void Account::error(const std::string &msg) const {
    cout << "Error (# " << id << "): " << msg << endl;
}

SavingsAccount::SavingsAccount(const Date &date, const string &id, double rate) :
        Account(date, id), rate(rate), acc(date, 0) {}

void SavingsAccount::deposit(const Date &date, double amount, const std::string &desc) {
    record(date, amount, desc);
    acc.change(date, getBalance());
}

void SavingsAccount::withdraw(const Date &date, double amount, const std::string &desc) {
    if (amount > getBalance()) {
        error("not enough money");
    } else {
        record(date, -amount, desc);
        acc.change(date, getBalance());
    }
}

void SavingsAccount::settle(const Date &date) {
    double interest = acc.getSum(date) * rate / date.distance(Date(date.getYear() - 1, 1, 1));
    if (interest != 0) record(date, interest, "interest");
    acc.reset(date, getBalance());
}

CreditAccount::CreditAccount(const Date &date, const string &id, double credit, double rate, double fee) :
        Account(date, id), credit(credit), rate(rate), fee(fee), acc(date, 0) {}

void CreditAccount::deposit(const Date &date, double amount, const std::string &desc) {
    record(date, amount, desc);
    acc.change(date, getDebt());
}

void CreditAccount::withdraw(const Date &date, double amount, const std::string &desc) {
    if (amount - getBalance() > credit) {
        error("not enough credit");
    } else {
        record(date, -amount, desc);
        acc.change(date, getDebt());
    }
}

void CreditAccount::settle(const Date &date) {
    double interest = acc.getSum(date) * rate;
    if (interest != 0) record(date, interest, "interest");
    if (date.getMonth() == 1)
        record(date, -fee, "annual fee");
    acc.reset(date, getDebt());
}

void CreditAccount::show() const {
    Account::show();
    cout << "\tAvailable credit: " << getAvailableCredit();
}