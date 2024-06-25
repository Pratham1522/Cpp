#include "Saving.hpp"
#include "Current.hpp"
#include "HDFC.hpp"
#include "ICICI.hpp"
#define line() cout<<"---------------x------------------\n";

int main()
{
    line();
    Current current;
    current.setDB(new HDFC);
    current.exeTask(101, 1000);

    line();
    ICICI bank1;
    Saving saving;
    saving.setDB(bank1);
    saving.exeTask(101, 2000);

    line();
    return 0;
}
