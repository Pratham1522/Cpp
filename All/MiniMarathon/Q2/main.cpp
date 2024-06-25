#include <iostream>
#include "Flight_Management.h"

int main()
{
    int n=3;
    Flight obj[n];
    for (int i = 0; i < n; i++)
    {
        obj[i].FeedInfo();
        obj[i].ShowInfo();
    }
    searchFlight(obj,n);
    maxFare(obj,n);
    

    return 0;
}