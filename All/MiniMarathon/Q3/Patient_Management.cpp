#include<iostream>
using namespace std;

class Patient{
    private:
        int patientnumber;
        char* patientname;
        float* Temp;

        void Print(){
            cout<<"\nTemperature Array : {";
            for(int i=0;i<2;i++){
                cout<<Temp[i]<<" ,";
            }
            cout<<Temp[2]<<" } \n";
        }

    public:
        Patient(){
            patientnumber=0;
            patientname="*";
            Temp = new float[3];
        }    
        Patient(int pnumber ,char* pname ,float* arr){
            patientnumber=pnumber;
            patientname=pname;
            Temp=arr;
        }
        Patient(Patient &obj){
            patientnumber=obj.patientnumber;
            patientname=obj.patientname;
            Temp=new float[3];
            for(int i=0;i<3;i++){
                Temp[i]=obj.Temp[i];
            }
        }
        
        void calculateAvgTemperature(){
            float avg=0;
            for(int i=0;i<3;i++){
                avg+=Temp[i];
            }
            avg/=3;
            cout<<"\n*****************************";
            cout<<"Average Temperature is : "<<avg;
        }
        void display(){
            cout<<"\n**** Details of Patient ****";
            cout<<"\nPatient Number : "<<patientnumber;
            cout<<"\nPatient Name : "<<patientname;
            Print();
        }
};

int main(){
    Patient p1(2,"pratham",{11,22,20.1});
    p1.display();
    return 0;

}