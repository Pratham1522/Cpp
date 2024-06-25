#include "product.h"
#include<cstring>
Product::Product()
{
    pname = new char[10];
    strcpy(pname,"Mobile");   
}
Product::~Product()
{
    delete []pname;// avoid memory leakage 
    std::cout<<"\n ~Product() called ";
}
Product::Product(const char *nm)
{
    pname = new char[strlen(nm)+1];
    strcpy(pname,nm);   
}
void Product::display()
{
    std::cout<<"\n Product Name  = "<<pname;
}
