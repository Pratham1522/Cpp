#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include "Patienttype.h"

class Patient 
{
private:
    std::string _patientId {""};
    unsigned int _patientAge {0};
    PatientType _patientType {PatientType::NEW};

public:
    Patient() = default; // Default constructor
    Patient(const Patient&) = default; // Copy constructor
    Patient& operator=(const Patient&) = delete; // Copy assignment operator
    Patient(Patient&&) = delete; // Move constructor
    Patient& operator=(Patient&&) = delete; // Move assignment operator
    ~Patient() = default; // Destructor

    Patient(std::string id,unsigned int age,PatientType type);

    std::string patientId() const { return _patientId; }

    unsigned int patientAge() const { return _patientAge; }

    PatientType patientType() const { return _patientType; }
    void setPatientType(const PatientType &patientType) { _patientType = patientType; }

    friend std::ostream &operator<<(std::ostream &os, const Patient &rhs);
};

#endif // PATIENT_H
