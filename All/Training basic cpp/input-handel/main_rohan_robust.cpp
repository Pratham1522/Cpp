#include <iostream>
#include <limits>


/**
 * Case 1
 * =======
*/

double getDouble()
{
    double val {};

    while (true)
    {
        std::cout << "Enter number: ";
        std::cin >> val;

        if (std::cin.eof())
        {
            exit(0);
        }

        // if (std::cin.fail())
        if (!std::cin || (!std::cin.eof() && std::cin.peek() != '\n'))
        {
            std::cin.clear(); // set cin to normal mod
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return val;
        }
    }
}


char getOperator()
{
    char ch {};

    while (true)
    {
        std::cout << "Enter operator (+, -, *, /): ";
        std::cin >> ch;

        if (std::cin.eof())
        {
            exit(0);
        }

        if (!std::cin || (!std::cin.eof() && std::cin.peek() != '\n'))
        {
            std::cin.clear(); // set cin to normal mod
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            switch (ch)
            {
            case '+':
            case '-':
            case '*':
            case '/':
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return ch;
            }
        }
    }
}


int main(int argc, char **argv)
{
    double num1 { getDouble() };
    char op { getOperator() };
    double num2 { getDouble() };
    double result {};

    // std::cout << "Enter number 1: ";
    // std::cin >> num1;

    // std::cout << "Enter operator (+, -, *, /): ";
    // std::cin >> op;

    // std::cout << "Enter number 2: ";
    // std::cin >> num2;


    switch (op)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = num1 / num2;
        break;
    default:
        std::cout << "Invalid operation\n";
    }

    std::cout << "Result : " << result << "\n";

    return 0;
}

