#include <iostream>
#include <list>

#include <Bank.h>
#include <Account.h>
#include <Semaphore.h>

using namespace std;

int main()
{
    Bank bank;
    bank.insert_account(200.0, "Ana");
    bank.insert_account(43345.34, "B");
    bank.insert_account(5465.3, "C");
    bank.print_accounts();
    
    bank.deposit(10, "Ana");
    bank.drawOut(250, "Ana");
    bank.drawOut(205, "Ana");
    
    bank.account_updater(0.12);
    
    bank.print_accounts();
    
    return 0;
}
