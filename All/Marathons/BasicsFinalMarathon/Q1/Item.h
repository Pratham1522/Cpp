#pragma once
#include <iostream>

enum ptype
{
    BURGER = 1,
    PIZZA
};
class Item
{
private:
    int Product_type;
    int Numberofitems;
    int cashinhand;
    int costperitem;

public:
    Item();
    void sellitem();
};
