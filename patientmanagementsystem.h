#ifndef PATIENTMANAGEMENTSYSTEM_H
#define PATIENTMANAGEMENTSYSTEM_H
#include "patient.h"
#include "qtmetamacros.h"
#include<vector>

class PatientManagementSystem
{
private:
    std::vector<Patient> patients;
public:
    PatientManagementSystem();
public slots:
    void addPatient(const Patient& patient);
    void removePatient(const Patient& patient);
};

#endif // PATIENTMANAGEMENTSYSTEM_H
