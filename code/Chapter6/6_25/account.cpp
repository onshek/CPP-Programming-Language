#include "account.h"
#include <cmath>
#include <iostream>

using namespace std;

double SavingsAccount::total = 0;

SavingsAccount::SavingsAccount(const Date &date, const std::string &id, double rate)
        : id(id), balance(0), rate(rate), lastDate(date), accumulation(0) {
    date.show();
    cout << "\t#" << id << " created" << endl;
}

void SavingsAccount::record(const Date &date, double amount, const std::string &desc) {
    accumulation = accumulate(date);
    lastDate = date;
    amount = floor(amount * 100 + 0.5) / 100;
    balance += amount;
    total += amount;
    date.show();
    cout << "\t#" << id << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}

void SavingsAccount::error(const std::string &msg) const {
    cout << "Error(#" << id << ")" << msg << endl;
}

void SavingsAccount::deposit(const Date &date, double amount, const std::string &desc) {
    record(date, amount, desc);
}

void SavingsAccount::withdraw(const Date &date, double amount, const std::string &desc) {
    if (amount > getBalance())
        error("not enought money");
    else
        record(date, -amount, desc);
}

void SavingsAccount::settle(const Date &date) {
    double interest = accumulate(date) * rate / date.distance(Date(date.getYear() - 1, 1, 1));
    if (interest != 0)
        record(date, interest, "interest");
    accumulation = 0;
}

void SavingsAccount::show() const {
    cout << id << "\tBalance: " << balance;
}