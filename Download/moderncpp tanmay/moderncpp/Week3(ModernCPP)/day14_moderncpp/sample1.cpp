/*
 Objective : Main Thread will take an input from user. The input number's factorial will be calculated in the factorial function which performs the folloowing actions.


 a)Allocate memory for 4 byte factorial result.
 b)Actually calculate factorial
*/

#include <future>
#include <thread>
#include <iostream>

void factorial(std::future<int> &number)
{
    int* answer = (int*) malloc(4); //statement can execute even before input.

    /*
    since pre-requisite task is done, malloc is finished , now I really need the input without which i cannot proceed! 
    */
   int n= number.get(); //wait till input arrives.
   
   int final_result{1};

   for(int i=2;i<=n;i++){
    final_result *=i;
   }
   *answer = final_result;
   std::cout<<"Factorial calculatio " << *answer ;

}

// ft---> used for reading.
// pr--->used for writting.

int main()
{

    // I want to make an promise to provide an integer.

    std::promise<int> pr;

    std::future<int> ft = pr.get_future();

    std::future<void> result = std::async(&factorial, std::ref(ft));
    factorial;
    int value{0};
    std::cin >> value;

    pr.set_value(value);
    //
    result.wait();

    return 0;
}

