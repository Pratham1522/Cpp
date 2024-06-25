

/*
accept 5 numbers as input frmo user
after inputs are received, concurrently perform :
a) find sq of each number and store it in a result var "output"(in 1 to 5 slots)
b) find cube of each number and store it in a result var "output"(in 6 to 10 slots)
c)find factorial of each number and store it in a result variable output(in 11 to 15 slots)
constaint: input cannot be negative. Number cannot be more than 10 if invalid input is received,
prompt tge user to reenter the number.
  */
#include "Functionalities.h"




int main(){
    resultContainer result;
    inputContainer inputArr;
    ThreadsArray th;
    Input(inputArr);
    MapThreadsToFunctions(th,inputArr,result);
    Display(result);

}
