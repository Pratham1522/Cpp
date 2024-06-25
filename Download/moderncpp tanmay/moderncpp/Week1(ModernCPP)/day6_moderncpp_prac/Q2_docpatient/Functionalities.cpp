#include "Functionalities.h"

void CreateObjects(Container &data)
{
    data.push_back(new Doctor(
        "123",6000.0f,DoctorType::CARDIOLOGIST,
        new Patient("111",45,PatientType::REGULAR)
    ));
    data.push_back(new Doctor(
        "234",2000.0f,DoctorType::GENERALPHYSICIAN,
        new Patient("222",35,PatientType::REGULAR)
    ));
    data.push_back(new Doctor(
        "345",4000.0f,DoctorType::CARDIOLOGIST,
        new Patient("222",50,PatientType::NEW)
    ));
    data.push_back(new Doctor(
        "456",5000.0f,DoctorType::NEUROLOGIST,
        new Patient("222",16,PatientType::NEW)
    ));
}

int CountOfValAbove5000(Container &data)
{
    int count=0;
    for(Doctor* obj:data){
        if(obj && obj->doctorFees()>=5000){
            count++;
        }
    }
    return count;
}

void CheckCardiologistAvailability(Container &data)
{
    for(Doctor* obj:data){
        if(obj && obj->doctorType()==DoctorType::CARDIOLOGIST){
            std::cout<<*obj;
        }
    }
}

double CheckAverageOfPatient(Container &data)
{
    double total=0.0f;
    double count=0;
    for(Doctor* obj:data){
        if(obj){
            count++;
            total += obj->doctorCurrentPatient()->patientAge();
        }
    }
    return static_cast<double>(total/count);
}

void Display(Container &data, int n)
{
    int count=0;
    if(n>data.size()){
        throw std::runtime_error("value of n is greater than size of container");
    }
    for(std::vector<Doctor*>::iterator it=data.rbegin();it!=data.rend();++it){
        if(count<n){
            //std::cout<<*obj;
            std::cout<<*obj->doctorCurrentPatient();
            count++;
        }
        else{
            break;
        }
    }
}

void deleteobjects(Container &data)
{
    for(Doctor* obj:data){
        if(obj){
            if(obj->doctorCurrentPatient()){
                delete obj->doctorCurrentPatient();
            }
        }
        delete obj;
    }
}
