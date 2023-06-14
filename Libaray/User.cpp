//
// Created by 20115 on 6/12/2023.
//
#include "User.h"
int User::count=0;
User::User() {
    name="";
    age=0;
    password="";
    email="";
    id=++count;

}
User::User(string name, int age, string password, string email) {
    this->name=name;
    this->age=age;
    this->password=password;
    this->email=email;
    id=++count;
}
User::User(const User & obj) {
    name=obj.name;
    age=obj.age;
    password=obj.password;
    email=obj.email;
    id=obj.id;

}
/*
void User::operator=(const User & obj) {
    name=obj.name;
    age=obj.age;
    password=obj.password;
    email=obj.email;

}*/

void User::setName(string name) { this->name=name;}
string User::getName() const {return name;}

void User::setAge(int age) {this->age=age;}
int User::getAge() const {return  age;}

void User::setEmail(string email) {this->email=email;}
string User::getEmail() const {return email;}

void User::setPassword(string password) { this->password=password;}
string User::getPassword() const {return password;}

void User::setId(int id) { this->id=id;}
int User::getId() const {return id;}

bool User::operator==(const User &user)  //user1==user2
{
    return (id==user.id && email==user.email && name==user.name && age==user.age);
}

istream  &operator>>(istream & is, User &user)
{
    cout<<"Enter the User information in this order "<<endl;
    cout<<"name   Email  Age  password"<<endl;
    is>>user.name>>user.email>>user.age>>user.password;
    return is;
}

ostream &operator<<(ostream & os, const User & user)
{
    os<<"---------------------------------------"<<endl;
    os<<"user Name: "<<user.name<<"  |  ";
    os<<"user ID: "<<user.id<<"  |  ";
    os<<"user Email: "<<user.email<<"  |  ";
    os<<"user age: "<<user.age<<endl;
    os<<"------------------------------------"<<endl;
    return os;


}