#ifndef NURSE_H
#define NURSE_H
#include "user.h"

class Nurse : public User
{
public:
    Nurse(const QString& username, const QString& password)
        : User(username, password) {}
public slots:
    void login() override;
};

#endif // NURSE_H
