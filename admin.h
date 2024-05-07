#ifndef ADMIN_H
#define ADMIN_H
#include "user.h"
#include<QObject>
#include "doctor.h"
#include <vector>

class Admin : public QObject, public User
{
    Q_OBJECT
public:
    Admin(const QString& username, const QString& password):User(username, password){};

public slots:
    void login() override;
};

#endif // ADMIN_H
