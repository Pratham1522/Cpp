/* #include<iostream>

void f1(int* ptr)
{
    ptr = new int[1000];
    for(int i=0;i<1000;i++){
        *(ptr+i) = i+1;
    }
}

void f2(int* ptr){
    for(int i=0;i<1000;i++){
        std::cout<<*(ptr+i) * *(ptr+i);
    }
}
int main(){
    int *ptr = nullptr;
    f1(ptr);
    f2(ptr);

    //ptr should no longer work. sptr shoul get access to data.
    int *sptr = ptr;
    ptr = nullptr;
}
 */

#include<iostream>


class vehicle{
    private:
        int vehicleID;
        float price;
    public:
        vehicle(int id, float amt): vehicleID(id), price(amt){

        }
        ~vehicle(){}
};

void magic(vehicle n1){

}

int main(){
    //4 tokens --> (int is datatype token, n1 is a variable token, = is an assignment operator which is a token, 10 is an integere literal token)
    int n1 = 10;
    //literal value 10 is craeted in c then it was transferred via data bus location in RAM
    10;//create 10 in register.
    
    magic(vehicle(100,101.0f));
    
}
//IF VARIABLE NAME IS NOT GIVEN THEN IT IS A RVALUE
