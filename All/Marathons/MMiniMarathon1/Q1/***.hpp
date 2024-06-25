#pragma once
#include "car.hpp"
# define line(msg) cout<<"\n______________"#msg"_______________\n";


class bookingCar{
    static map<int ,Car* > booking;
    friend void calFare(int ,int );
    friend void searchVendor(string s );
    public:
    bookingCar(int id ,Car* car1){
        bookCar(id ,car1);
    }
    void bookCar(int id,Car* car1)
    {
        booking[id]=car1;
    }
    void cancel(int id)
    {
        delete booking[id];
        booking.erase(id);
    } 
};
map<int ,Car* > bookingCar::booking;

void calFare(int id,int km){
    float totalCost;
    float vendorShare; 
    for(auto rng: bookingCar::booking) {
        int bId=rng.first;
        if(id==bId){
            Car* car1= rng.second;
            Vendor* v = car1->getVendor();
            int temp = car1->getPerKmCharge() *km;
            vendorShare= temp* v->getVendorCharges() /100;
            totalCost=temp + vendorShare;
            
            cout<<"Car num : "<<car1->getNumber();
            cout<<"\nVendor : "<<v->getvendorId();
            cout<<"\nVendor per :"<<v->getVendorCharges();
            cout<<"\nDist :"<<km;
            cout<<"\nTotal Fare :"<<totalCost;
            cout<<"\nVendor Fare : "<<vendorShare;
            line(xxxx);
        }
        
    }
} 
void searchVendor(string s ){
    int flag=0;
    cout<<"For vendor : "<<s<<" \n";
    for(auto rng: bookingCar::booking) {
        int bId=rng.first;
        Car* car1= rng.second;
        Vendor* v = car1->getVendor();
        if(s==v->getvendorId())
        {
            flag=1;
            cout<<"Booking Id : "<<bId<<" found. \n";
        }
    }
    if (flag==0){
        cout<<"No booking found";
    }
    line(xxxx);
}
void Init()
    {


        Vendor* vendor1=new Vendor("Rapido",2);
        Vendor* vendor2=new Vendor("Ola",3);
        Vendor* vendor3=new Vendor("IRTC",2.5);
        Vendor* vendor4=new Vendor("Uber",4);
        Vendor* vendor5=new Vendor("FabHotels",5);

        VendorRepository::Register(vendor1);
        VendorRepository::Register(vendor2);
        VendorRepository::Register(vendor3);  //change
        VendorRepository::Register(vendor4);
        VendorRepository::Register(vendor5);

        Car* car1=new Car("mh15fz3404",4,12,vendor2);
        Car* car2=new Car("mh15fz3405",4,10,vendor1);
        Car* car3=new Car("mh15fz3406",6,15,vendor4);
        Car* car4=new Car("mh15fz3407",4,14,vendor3);
        Car* car5=new Car("mh15fz3408",6,18,vendor5);

        bookingCar p1(001 ,car1);
        bookingCar p2(002,car2);
        bookingCar p3(003,car3);
        bookingCar p5(004, car4);
        bookingCar p4(005, car5);

        for(int i=1;i<6;i++){
            calFare(i,100);
        }
        searchVendor("Ola");
        searchVendor("Demo");
}

