//
// Created by 20115 on 6/12/2023.
//
#include "string"
#include "bits.h"
#include "iostream"
using namespace std;
#ifndef LIBARAY_USER_H
#define LIBARAY_USER_H

class User{
private:
    string name;
    int age;
    int id;
    string password;
    string email;
public:
    static int count;
    User();
    User(string  , int  , string  , string  );
    User(const User& );
    bool operator==(const User&  );
    void setName(string );
    string getName() const;
    void setPassword(string );
    string getPassword()const;
    void setEmail(string );
    string getEmail()const ;
    void setAge(int );
    int getAge() const;
    void setId(int );
    int getId() const;
   // void operator=(const User & obj) ;
    friend ostream &operator<<(ostream &, const User &);
    friend istream &operator>>( istream & , User &);
};



#endif //LIBARAY_USER_H
