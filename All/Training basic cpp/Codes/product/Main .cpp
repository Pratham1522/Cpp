#include<iostream>
#include"product.h"
int main()
{
    //  Product p1;
    //  p1.display();

    Product p2("Laptop");
    p2.display();

    Product p3(p2);//copy p2 object into p3 object
    p3.display();

    Product *ptr=new Product("Bag");
    ptr->display();
   

    delete ptr;
}