#include<iostream>

int *solve(int a){
    int *x = &a;
    return x;
}

class vehicle{
    private:
        int vehicleID;
        float price;
    public:
        vehicle(int id, float amt): vehicleID(id), price(amt){

        }
        ~vehicle(){}
};
void sol(vehicle **v, int size){

}
int main(){
    vehicle* arr[]={
        new vehicle(100,10.0f), new vehicle(101,123.0f)
    };
}

