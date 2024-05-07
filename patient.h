#ifndef PATIENT_H
#define PATIENT_H
#include "user.h"

class Patient
{
public:
    Patient();
    QString username;
    std :: vector <QString> Number;
    // Patient(const QString& username, const QString& password)
    //     : User(username, password) {}
public slots:
    // void login() override;
};

#endif // PATIENT_H
