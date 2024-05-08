#include "user.h"
#include<vector>

std::vector<QString> usernames = {"admin", "test", "user1", "user2", "dalia"};
std::vector<QString> passwords = {"admin", "1234", "1101", "1102", "1234"};

User::User(const QString& username, const QString& password)
    : username(username), password(password) {
}



