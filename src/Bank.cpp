#include "Bank.h"

void Bank::insert_account(double balance, string owner) {
    Account temp_account(balance, owner);
    accounts.push_back(temp_account);
}

void Bank::deposit(double value, string owner) {
    list<Account>::iterator it;
    for (it = accounts.begin(); it != accounts.end(); it++) {
        if (((*it).get_owner()).compare(owner) == 0) {
            (*it).deposit(value);
            usleep(1 * 1000);
        }
    }
}

void Bank::drawOut(double value, string owner) {
    list<Account>::iterator it;
    for (it = accounts.begin(); it != accounts.end(); it++) {
        if (((*it).get_owner()).compare(owner) == 0) {
            (*it).drawOut(value);
            usleep(1 * 1000);
        }
    }
}

void Bank::account_updater(double tax) {
    list<Account>::iterator it;
    for (it = accounts.begin(); it != accounts.end(); it++) {
        (*it).update(tax);
        usleep(1 * 1000);
    }
}

void Bank::print_accounts() {
    list<Account>::iterator it;
    for (it = accounts.begin(); it != accounts.end(); it++) {
        cout << "Owner: " << (*it).get_owner();
        cout << " | Balance: " << (*it).get_balance() << "$" << endl;
    }
}
