#include <iostream>
#include <list>

#include <Bank.h>
#include <Account.h>
#include <Semaphore.h>

using namespace std;

int main()
{
    Bank bank;
    bank.insert_account(234.0, "Ana");
    bank.insert_account(9987.42, "Beatriz");
    bank.insert_account(2313.7, "Carla");
    bank.print_accounts();

    return 0;
}
