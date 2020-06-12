#include <iostream>
#include <cstdlib>
#include <list>
#include <chrono>

#include <Bank.h>
#include <Account.h>

#define NUMBER_OF_ACCOUNTS 10000
#define NUMBER_OF_OPERATIONS 10000

using namespace std;

double durationUpdt = 0;

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

        auto startTimeUpdt = std::chrono::high_resolution_clock::now();
        // Performs account_updater 10 times
        if ((i+1) % (NUMBER_OF_OPERATIONS/10) == 0) {
            double tax = (double)rand() / RAND_MAX; // double number between 0 and 1
            bank.account_updater(tax);
        }
        auto stopTimeUpdt = std::chrono::high_resolution_clock::now();
        durationUpdt += std::chrono::duration_cast<std::chrono::microseconds>(stopTimeUpdt - startTimeUpdt).count();
    }
}

int main()
{
    Bank bank;
    create_accounts(bank);
    bank.print_accounts();
    auto startTime = std::chrono::high_resolution_clock::now();
    multiple_operations(bank);
    auto stopTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);
    bank.print_accounts();

    cout << "\nDuration: " << duration.count() << " microseconds";
    cout << "\nDuration: " << duration.count() / 1000 << " miliseconds" << endl;
    cout << "\nUpdater duration: " << durationUpdt << " microseconds";
    cout << "\nUpdater duration: " << durationUpdt / duration.count() << " %" << endl;

    return 0;
}
