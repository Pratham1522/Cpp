#include "Patient.h"

Patient::Patient(std::string id, unsigned int age, PatientType type)
    :_patientId(id), _patientAge(age), _patientType(type)
{
}
std::ostream &operator<<(std::ostream &os, const Patient &rhs) {
    os << "_patientId: " << rhs._patientId
       << " _patientAge: " << rhs._patientAge
       << " _patientType: "; 
       if(static_cast<int>(rhs._patientType)==0){
            os<<"REGULAR";
       }
       else if(static_cast<int>(rhs._patientType)==1){
        os<<"NEW";
       }
    return os;
}
