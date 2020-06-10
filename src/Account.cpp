#include <iostream>
#include "Account.h"

using namespace std;

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
    cout << "--- ["<< _owner << "|" << _balance << "] Updating account with " << tax << "% rate." << endl;
    // Here can occur a problem because of thread changing
    _balance = new_balance;
    
    cout << "--- ["<< _owner << "|" << _balance << "] Updated account." << endl;
}

void Account::deposit(double value) {
    double new_balance = _balance + value;
    cout << "--- ["<< _owner << "|" << _balance << "] Making deposit of " << value << "$." << endl;
    // Here can occur a problem because of thread changing
    _balance = new_balance;
    
    cout << "--- ["<< _owner << "|" << _balance << "] " << value << "$ deposit made." << endl;
}

void Account::drawOut(double value) {
    double new_balance;
    if(_balance - value >= 0) {
        new_balance = _balance - value;
        cout << "--- ["<< _owner << "|" << _balance << "] Making withdrawal of " << value << "$." << endl;
        // Here can occur a problem because of thread changing
        _balance = new_balance;
        
        cout << "--- ["<< _owner << "|" << _balance << "] " << value << "$ withdrawal made." << endl;
    } else {
        new_balance = _balance;
        cout << "--- ["<< _owner << "|" << _balance << "] Balance unavailable to withdrawal." << endl;
    }
}

double Account::get_balance() {
    return _balance;
}

string Account::get_owner() {
    return _owner;
}
