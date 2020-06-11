#include <iostream>
#include <list>

#include <Bank.h>
#include <Account.h>
#include <Semaphore.h>

#define NUMBER_OF_ACCOUNTS 10

using namespace std;

void create_accounts(Bank &bank) {
    for (int i = 0; i < NUMBER_OF_ACCOUNTS; i++)
        bank.insert_account(10.0 * i * i, "Client" + to_string(i+1));
}

int main()
{
    Bank bank;

    create_accounts(bank);
    bank.print_accounts();

    bank.account_updater(0.12);

    bank.print_accounts();

    return 0;
}
