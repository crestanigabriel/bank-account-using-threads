#include <thread>

#include "Bank.h"

Bank::Bank()
{
    //ctor
}

Bank::~Bank()
{
    //dtor
}

void Bank::insert_account(double balance, string owner) {
    Account temp_account(balance, owner);
    accounts.push_back(temp_account);
}

void Bank::deposit(double value, string owner) {
    list<Account>::iterator it;
    for (it = accounts.begin(); it != accounts.end(); it++) {
        if (((*it).get_owner()).compare(owner) == 0)
            (*it).deposit(value);
    }
}

void Bank::drawOut(double value, string owner) {
    list<Account>::iterator it;
    for (it = accounts.begin(); it != accounts.end(); it++) {
        if (((*it).get_owner()).compare(owner) == 0)
            (*it).drawOut(value);
    }
}

void Bank::account_updater(double tax) {
    list<Account>::iterator it;
    //sequential
    for (it = accounts.begin(); it != accounts.end(); it++) {
        (*it).update(tax);
    }
 
    //multithreading
    list<Account> accounts;
    thread updatedAccountsThreads[accounts.size()];
    for (int i = 0; i < accounts.size(); i++) {
        // updatedAccountsThreads[i] = thread(accounts[i].update, tax);
        updatedAccountsThreads[i].join();
    }
}

void Bank::print_accounts() {
    list<Account>::iterator it;
    for (it = accounts.begin(); it != accounts.end(); it++) {
        cout << "Owner: " << (*it).get_owner();
        cout << " | Balance: " << (*it).get_balance() << "$" << endl;
    }
}
