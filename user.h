#ifndef USER_H
#define USER_H
#include <QString>

extern std::vector<QString> usernames;
extern std::vector<QString> passwords;
extern std::vector<QString> roles;

 // QString usernames[100] = {"admin", "test", "user1", "user2"};
 // QString passwords[100] = {"admin", "1234", "1101", "1102"};


class User
{
protected:

    QString username;
    QString password;
public:
    User(const QString& username, const QString& password);
public slots:
    virtual void login() = 0;
};

#endif // USER_H

