#ifndef STAFFMANAGEMENTSYSTEM_H
#define STAFFMANAGEMENTSYSTEM_H
#include<vector>
#include "doctor.h"
#include "nurse.h"
#include "qtmetamacros.h"

class StaffManagementSystem
{
private:
    std::vector<Doctor> doctors;
    std::vector<Nurse> nurses;
public:
    StaffManagementSystem();
public slots:
    void addDoctor(const Doctor& doctor);
    void removeDoctor(const Doctor& doctor);
    void addNurse(const Nurse& nurse);
    void removeNurse(const Nurse& nurse);
    void manageSchedule();
};

#endif // STAFFMANAGEMENTSYSTEM_H
