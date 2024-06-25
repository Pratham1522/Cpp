#include <future>
#include <thread>
#include <iostream>

// usage of future
class FactorialCalculator
{
private:
    // FactorialCalculator() {}
    static FactorialCalculator *instance;

public:
    static FactorialCalculator *getInstance()
    {
        if (!instance)
        {
            instance = new FactorialCalculator();
        }
        return instance;
    }

    void calculateFactorial(std::future<int> &number)
    {
        int *answer = (int *)malloc(sizeof(int));

        int n = number.get();

        int final_result = 1;

        for (int i = 2; i <= n; i++)
        {
            final_result *= i;
        }
        *answer = final_result;
        std::cout << "Factorial calculation: " << *answer << std::endl;
    }
};

FactorialCalculator *FactorialCalculator::instance = nullptr;

int main()
{

    FactorialCalculator *calculator = FactorialCalculator::getInstance();

    std::promise<int> pr;
    std::future<int> ft = pr.get_future();

    std::future<void> result = std::async(&FactorialCalculator::calculateFactorial, calculator, std::ref(ft));

    int value;
    std::cout << "Enter a number: ";
    std::cin >> value;

    pr.set_value(value);

    result.wait();

    return 0;
}


