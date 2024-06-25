#ifndef PRODUCT_H
#define PRODUCT_H
#include<iostream>
#include<cstring>
class Product
{
   
    char *pname;
   
    public:    
        Product();
        Product(const Product &p)
        {
            //p3----this
            //p2----p

            this->pname= new char[strlen(p.pname)+1];
            strcpy(this->pname,p.pname);           
        }

        Product(const char *);
        void display();
        ~Product();//cannot be overloaded             
        
};
#endif // PRODUCT_H
