#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

using namespace std;

class Account
{
public:
    Account(double balance, string owner);

    void update(double tax);
    void deposit(double value);
    void drawOut(double value);
    double get_balance();
    string get_owner();

protected:

private:
    double _balance;
    string _owner;
};

#endif // ACCOUNT_H
