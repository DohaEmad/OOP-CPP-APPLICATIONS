//
// Created by 20115 on 6/12/2023.
//
#include "User.h"
#ifndef LIBARAY_USERLIST_H
#define LIBARAY_USERLIST_H


class UserList {
private:
    User** users;
    int capacity;
    int usersCount;
public:
    UserList(int capacity);
    void addUser(User &user); // at the end of the array.
    User* searchUser(string name);
    User* searchUser(int id);
    void deleteUser(int id);
    friend ostream &operator<<( ostream &output, UserList &userList );//to display all
    ~UserList();

};


#endif //LIBARAY_USERLIST_H
