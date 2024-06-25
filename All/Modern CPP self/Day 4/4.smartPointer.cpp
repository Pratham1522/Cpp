#include<iostream>
using std::cout;
#define line(msg)   cout<<"--------------(msg)--------------------\n";

class CA
{
    public:
        CA()
        {
            cout<<"CA C-tor\n";
        }
        void fun()
        {
            cout<<"CA Fun\n";
        }
        ~CA()
        {
            cout<<"CA D-tor\n";
        }
};
void DoBussiness(CA* caPtr)   //CA* to smartpointer conversion req.
{
    cout<< "Bussiness started \n";
    caPtr->fun();
    cout<<"Bussiness Done\n";
}

class Smart_ptr{
    //Memory should not go in heap
    static void* operator new(size_t) = delete;
    static void* operator new[](size_t) = delete;
    static void operator delete(void*) = delete;
    static void operator delete[](void*) = delete;  

    CA* pt;

    public:
        Smart_ptr(CA* pt=NULL):pt(pt)
        {

        }
        //ownership transfer
        Smart_ptr(const Smart_ptr& par):pt(par.pt)
        {
            Smart_ptr& parRef = const_cast<Smart_ptr&>(par);
            parRef.pt=NULL;
        }
        Smart_ptr& operator=(const Smart_ptr& par)   //swapping ,sol for line 93[48,56]
        {
            Smart_ptr temp(par);
            temp.Swap(*this);
            return *this;
        }
        void Swap(Smart_ptr& tmp){
            std::swap(this->pt,tmp.pt);
        } 
        //to access CA functions using smartptr 
        CA* operator->()         //sol to my bussiness 
        {
            return pt;
        }
        CA& operator*()
        {
            return *pt;
        }
        operator CA* (){   //solution to doBussiness
            return pt;
        }
        ~Smart_ptr()
        {
            delete pt;
        }
};

void myBussiness(Smart_ptr smpt)   //dangling pointer : deep copy, ownership transfer, reference pointer
{
    cout<<"Apple\n";
    smpt->fun();
    cout<<"Orange\n";
}
int main()
{
    Smart_ptr sm1 = new CA();
    Smart_ptr sm1_1 = new CA();
    // sm1->fun();
    // (*sm1).fun();
    line();
    DoBussiness(sm1);
    line();
    myBussiness(sm1);
    line();
    Smart_ptr sm2;
    sm2=sm1_1;
    line();    
    return 0;
}