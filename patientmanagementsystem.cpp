#include "patientmanagementsystem.h"

PatientManagementSystem::PatientManagementSystem() {}

void PatientManagementSystem::addPatient(const Patient& patient) {
    patients.push_back(patient);
}

void PatientManagementSystem::removePatient(const Patient& patient) {
    // Remove patient from the list
}
