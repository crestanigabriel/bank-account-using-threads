#ifndef BANK_H
#define BANK_H

#include <Account.h>

#include <iostream>
#include <list>
#include <string>
#include <unistd.h>

using namespace std;

class Bank
{
public:
    Bank();
    virtual ~Bank();

    void insert_account(double balance, string owner);
    void deposit(double value, string owner);
    void drawOut(double value, string owner);
    void account_updater(double tax);
    void print_accounts();

protected:

private:
    list<Account> accounts;
};

#endif // BANK_H
