#include "Functionalities.h"
#include <future>
#include <iostream>

int main()
{
    Container c1;

    std::future<std::list<Shared_Tourist>> result;
    std::future<float> result1;
    std::future<std::string> result2;


    CreateObjects(c1);
    TouristVehicleType t1 = TouristVehicleType::CAB;

    try
    {
        result1 = std::async(&AverageBookingChargeForGivenType, std::ref(c1), std::ref(t1));
        std::cout << "Average Booking Charge: " << result1.get();
    }
    catch(EmptyContainerException& e)
    {
        std::cerr << e.msg() << "\n";
    }
    catch(NoInstanceException& e)
    {
        std::cerr << e.msg() << "\n";
    }


    try
    {
        result2 = std::async(&FindMaxChargeId, std::ref(c1));

        std::cout << "\nMax Id: " << result2.get() << "\n";
    }
    catch(EmptyContainerException& e)
    {
        std::cerr << e.msg() << "\n";
    }
    

    std::promise<unsigned int> pr;
    std::future<unsigned int> ft = pr.get_future();

    try
    {
        result = std::async(&FindFirstNInstance, std::ref(c1), std::ref(ft));
        pr.set_value(1);

        std::list<Shared_Tourist> ans = result.get();

        std::cout << "First N Instances: " << "\n";
        for(Shared_Tourist i : ans)
        {
            std::cout << *i << "\n";
        }

    }
    catch(EmptyContainerException& e)
    {
        std::cerr << e.msg() << "\n";
    }
    catch(NoInstanceException& e)
    {
        std::cerr << e.msg() << "\n";
    }
    catch(InvalidInputException& e)
    {
        std::cerr << e.msg() << "\n";
    }
    catch(ConditionDoesNotMatchException& e)
    {
        std::cerr << e.msg() << "\n";
    }

    return 0;
}



/*
    -------------------- BASIC FUTURE ERROR EXCEPTION --------------------
    broken_promise : pr.set_value() - Did not occur in the code. 

    future_already_retrieved : Two get() in a single async thread.
    
    no_state : Fetch something from the future variable for 
               the first time but their is nothing present in the variable.

               ---- Trying to work with an async thread which is not valid anymore. 

    promise_already_satisfied : pr.set_value() - Value is already set and you are 
                                                 trying to set it's value again. 
*/