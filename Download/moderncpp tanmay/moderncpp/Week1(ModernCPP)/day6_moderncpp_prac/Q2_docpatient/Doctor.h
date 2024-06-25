#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include "Patient.h"
#include "DoctorType.h"

class Doctor 
{
private:
    std::string _doctorId {""};
    float _doctorFees {0.0f};
    DoctorType _doctorType {DoctorType::GENERALPHYSICIAN};
    Patient* _doctorCurrentPatient {nullptr};

public:
    Doctor() = default; // Default constructor
    Doctor(const Doctor&) = default; // Copy constructor
    Doctor& operator=(const Doctor&) = delete; // Copy assignment operator
    Doctor(Doctor&&) = delete; // Move constructor
    Doctor& operator=(Doctor&&) = delete; // Move assignment operator
    ~Doctor() = default; // Destructor
    Doctor(std::string id,float fees, DoctorType type, Patient* ptr);

    std::string doctorId() const { return _doctorId; }

    float doctorFees() const { return _doctorFees; }

    DoctorType doctorType() const { return _doctorType; }
    void setDoctorType(const DoctorType &doctorType) { _doctorType = doctorType; }

    Patient* doctorCurrentPatient() const { return _doctorCurrentPatient; }
    void setDoctorCurrentPatient(Patient* doctorCurrentPatient) { _doctorCurrentPatient = doctorCurrentPatient; }

    friend std::ostream &operator<<(std::ostream &os, const Doctor &rhs);
};

#endif // DOCTOR_H
