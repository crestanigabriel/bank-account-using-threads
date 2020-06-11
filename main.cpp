#include <iostream>
#include <cstdlib>
#include <list>

#include <Bank.h>
#include <Account.h>
#include <Semaphore.h>

#define NUMBER_OF_ACCOUNTS 10
#define NUMBER_OF_OPERATIONS 100

using namespace std;

void create_accounts(Bank &bank) {
    for (int i = 0; i < NUMBER_OF_ACCOUNTS; i++)
        bank.insert_account(10.0 * i * i, "Client" + to_string(i+1));
}

void multiple_operations(Bank &bank) {
    for (int i = 0; i < NUMBER_OF_OPERATIONS; i++) {
        int operation = rand()%2; // 0 -> drawout, 1 -> deposit
        double value = ((double)rand() / RAND_MAX) * 1000.0; // double number between 0 and 1000
        string client = "Client" + to_string(rand()%NUMBER_OF_ACCOUNTS + 1);

        switch (operation) {
            case 0: bank.drawOut(value, client); break;
            case 1: bank.deposit(value, client); break;
        }
        // Performs account_updater 10 times
        if ((i+1) % (NUMBER_OF_OPERATIONS/10) == 0) {
            double tax = (double)rand() / RAND_MAX; // double number between 0 and 1
            bank.account_updater(tax);
        }
    }
}

int main()
{
    Bank bank;
    create_accounts(bank);

    bank.print_accounts();

    multiple_operations(bank);

    bank.print_accounts();

    return 0;
}
