#include "Doctor.h"

Doctor::Doctor(std::string id, float fees, DoctorType type, Patient *ptr)
    :_doctorId(id), _doctorFees(fees), _doctorType(type), _doctorCurrentPatient(ptr)
{
}

std::ostream &operator<<(std::ostream &os, const Doctor &rhs) {
    os << "_doctorId: " << rhs._doctorId
       << " _doctorFees: " << rhs._doctorFees
       << " _doctorType: "; 
       if(static_cast<int>(rhs._doctorType)==1){
            os<<"NEUROLOGIST";
       }
       else if(static_cast<int>(rhs._doctorType)==2){
            os<<"DERMALOGIST";
       }
       else if(static_cast<int>(rhs._doctorType)==3){
            os<<"GENERALPHYSICIAN";
       }
       else if(static_cast<int>(rhs._doctorType)==0){
            os<<"CARDIOLOGIST";
       }
      // os<< " _doctorCurrentPatient: " << *rhs._doctorCurrentPatient;
    return os;
}
