//
// Created by 20115 on 6/5/2023.
//
#include "iostream"
#include "bits.h"
using namespace std;
#ifndef PROJ_STUDENT_H
#define PROJ_STUDENT_H
class Student {
private:
    string name;
    float *grades;
    int numSubjects;
    int year;
    static string years[4];
public:
    Student(string ,int , int);
    Student( const Student&);
    ~Student();
    float& operator[](int);
    string getYear();
    Student operator++(int);
    Student operator--(int);
    void display();

};
//string Student::years[4]={"first","second","third","fourth"};

#endif //PROJ_STUDENT_H
