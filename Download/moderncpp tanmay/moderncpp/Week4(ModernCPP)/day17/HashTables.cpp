#include <unordered_map>
#include <iostream>
#include <memory>
#include "Employee.h"

using StackObjects = std::unordered_map<std::string, Employee>;
using RawPointerObjects = std::unordered_map<std::string, Employee*>;
using SharedPointersObjects = std::unordered_map<std::string, std::shared_ptr<Employee>>;

void CreateObjects(StackObjects& data)
{
    /*
        Step 1: Choose key and value. 
        Step 2: Make a pair of key and value.
        Step 3: Emplace back the data into the pair. 
    */
    data.emplace
    (   
        // Pairs are only going to work with move semantics / rValues. 
        std::make_pair
        (
            "E101", 
            Employee
            (
                "E101", "Saanjh", 5000.0f, 22, "Pune"
            )
        )
    );

    data.emplace
    (   
        std::make_pair<std::string,Employee>
        (
            "E102", 
            Employee
            (
                "E102", "Adrika", 6000.0f, 21, "Hyderabad"
            )
        )
    );

    data.emplace
    (   
        std::make_pair
        (
            "E103", 
            Employee
            (
                "E103", "Harshit", 70000.0f, 28, "Pune"
            )
        )
    );


    data.emplace
    (   
        /*
            PAIRS only support move Semantics / rValues. 
                -- No call by value
                -- Return by value

            std::make_pair is a template function.
            Hence it will ask you what is the type of the key and the type of value. 

                    std::make_pair<std::string, Employee>

            Now this can be deduced via Compile Time Argument Deduction. 

            You can deduce template arguments for template functions since C++ 14.
            However, for template classes this feature is available since C++20.
            
            
        */
        std::make_pair
        (
            "E104", 
            Employee
            (
                "E104", "Saurabh", 9000.0f, 20, "Mumbai"
            )
        )
    );

}

void CreateObjects(RawPointerObjects& data)
{
    data.emplace
    (   
        std::make_pair<std::string, Employee*>
        (
            "E101", 
            new Employee
            (
                "E101", "Saanjh", 5000.0f, 22, "Pune"
            )
        )
    );

    data.emplace
    (   
        std::make_pair<std::string, Employee*>
        (
            "E102", 
            new Employee
            (
                "E102", "Adrika", 6000.0f, 21, "Hyderabad"
            )
        )
    );

    data.emplace
    (   
        std::make_pair<std::string, Employee*>
        (
            "E103", 
            new Employee
            (
                "E103", "Harshit", 70000.0f, 28, "Pune"
            )
        )
    );


    data.emplace
    (   
        std::make_pair<std::string, Employee*>
        (
            "E104", 
            new Employee
            (
                "E104", "Saurabh", 9000.0f, 20, "Mumbai"
            )
        )
    );

}

void CreateObjects(SharedPointersObjects& data)
{
    data.emplace
    (   
        std::make_pair<std::string, std::shared_ptr<Employee>>
        (
            "E101", 
            std::make_shared<Employee>
            (
                "E101", "Saanjh", 5000.0f, 22, "Pune"
            )
        )
    );

    data.emplace
    (   
        std::make_pair<std::string, std::shared_ptr<Employee>>
        (
            "E102", 
            std::make_shared<Employee>
            (
                "E102", "Adrika", 6000.0f, 21, "Hyderabad"
            )
        )
    );

    data.emplace
    (   
        std::make_pair<std::string, std::shared_ptr<Employee>>
        (
            "E103", 
            std::make_shared<Employee>
            (
                "E103", "Harshit", 70000.0f, 28, "Pune"
            )
        )
    );


    data.emplace
    (   
        std::make_pair<std::string, std::shared_ptr<Employee>>
        (
            "E104", 
            std::make_shared<Employee>
            (
                "E104", "Saurabh", 9000.0f, 20, "Mumbai"
            )
        )
    );
}

template<typename T>
void Display(T& data)
{
    for(auto [k, v] : data)
    {
        std::cout << "Key is: " << k << "\t" << "Value: " << v << "\n";
    }
}

int main()
{

    StackObjects s1;

    RawPointerObjects r1;

    SharedPointersObjects sp1;

    CreateObjects(s1);      // Populate or fill up the data container

    CreateObjects(r1);      // Populate or fill up the data container

    CreateObjects(sp1);     // Populate or fill up the data container

    Display<StackObjects>(s1);   
}


