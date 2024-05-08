#ifndef USER_H
#define USER_H
#include <QString>
#include <queue>

extern std::vector<QString> usernames;
extern std::vector<QString> passwords;
extern std::vector<QString> roles;

 // QString usernames[100] = {"admin", "test", "user1", "user2"};
 // QString passwords[100] = {"admin", "1234", "1101", "1102"};


extern std::queue<QString> Dr1_queue;
extern std::queue<QString> Dr2_queue;
extern std::queue<QString> Dr3_queue;

class User
{
protected:

    QString username;
    QString password;
public:
    User(const QString& username, const QString& password);
    static bool Dr_1;
    static bool Dr_2;
    static bool Dr_3;
public slots:
    virtual void login() = 0;
};

#endif // USER_H

