#include "Account.h"

Account::Account(double balance, std::string owner)
{
    //ctor
    _balance = balance;
    _owner = owner;
}

Account::~Account()
{
    //dtor
}

void Account::update(double tax) {
    double new_balance = _balance * (1 + tax);
    // Here can occur a problem because of thread changing
    _balance = new_balance;
}

void Account::deposit(double value) {
    double new_balance = _balance + value;
    // Here can occur a problem because of thread changing
    _balance = new_balance;
}

double Account::get_balance() {
    return _balance;
}

string Account::get_owner() {
    return _owner;
}
