#include <iostream>
#include <list>

#include <Bank.h>
#include <Account.h>
#include <Semaphore.h>

using namespace std;



int main()
{
    cout << "Hello world!" << endl;
    Bank bank;
    bank.insert_account(234.0, "Ana");
    bank.print_accounts();


    return 0;
}
