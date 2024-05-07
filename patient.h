#ifndef PATIENT_H
#define PATIENT_H
#include "user.h"

class Patient : public User
{
public:
    Patient(const QString& username, const QString& password)
        : User(username, password) {}
public slots:
    void login() override;
};

#endif // PATIENT_H
