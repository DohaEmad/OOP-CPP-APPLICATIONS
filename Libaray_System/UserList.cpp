//
// Created by 20115 on 6/12/2023.
//

#include "UserList.h"

UserList::UserList(int capacity) {
    users= new User*[capacity];
    this->capacity=capacity;
    usersCount=0;
}

void UserList::addUser(User &user)
{
    users[usersCount++]=&user;
}
User* UserList::searchUser(string name)
{
    for (int i = 0; i <usersCount ; ++i) {
        if(users[i]->getName()==name)
            return users[i];
    }
    return NULL;
}
User* UserList::searchUser(int id)
{
    for (int i = 0; i <usersCount ; ++i) {
        if(users[i]->getId()==id)
            return users[i];
    }
    return NULL;
}
void UserList::deleteUser(int id)
{
    for (int i = 0; i <usersCount ; ++i) {
        if(users[i]->getId()==id)
        {
            users[i]=NULL;
            for (int j = i; j <usersCount-1 ; ++j) {
                users[j]=users[j+1];
            }
            usersCount--;
        }
    }

}

ostream &operator<<( ostream &os, UserList &userList )
{
    for (int i = 0; i <userList.usersCount ; ++i) {
        os<<*(userList.users[i])<<endl;
    }
    return os;
}
UserList::~UserList() {
    delete[] users;  // Delete the array of User pointers
}


