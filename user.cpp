#include "user.h"
#include<vector>

std::vector<QString> usernames = {"admin", "test", "user1", "user2", "dalia"};
std::vector<QString> passwords = {"admin", "1234", "1101", "1102", "1234"};
std::vector<QString> roles = {"Admin", "Patient", "Patient", "Nurse", "Doctor"};

bool User::Dr_1 = false;
bool User::Dr_2 = false;
bool User::Dr_3 = false;

std::queue<QString> Dr1_queue;
std::queue<QString> Dr2_queue;
std::queue<QString> Dr3_queue;

User::User(const QString& username, const QString& password)
    : username(username), password(password) {
}



