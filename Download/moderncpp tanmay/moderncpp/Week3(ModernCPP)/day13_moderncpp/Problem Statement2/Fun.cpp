// Approach 1.

#include <thread>
#include <iostream>
#include <condition_variable>

int val = -1;
std::condition_variable cv;
std::mutex mt;
bool flag{false};

void Producer_Input()
{
    std::cin >> val;
    // trigger a signal after cin is done, to indicate that consumer.
    // can proceed with square calculation.
    flag = true;
    cv.notify_one();
}

void Consumer_Operation()
{
    int *result = (int *)malloc(4);
    //////////////////////////
    std::unique_lock<std::mutex> ul(mt);

    cv.wait(ul, []()
            { return flag; });

    *result = val * val;
    std::cout << " Square Calculation is complete " << *result << std::endl;
}

/*

t1 starts first                        [ask for the input, Now T1 is waiting for input]
                                        |
                                        |
                                        |
        start---> main starts -----> creates t1 ------> creates t2
                                                          |
                                                          |
                                                          |
                                                          |
                                                          |
                                                         [malloc]
                                                         a)t2 will apply a lock
                                                         b)check if input is received , yes or no
                                                         c)cv.wait checks a predicate
                                                            |
                                                            |
                                                            -------->if false, release the lock.

*/