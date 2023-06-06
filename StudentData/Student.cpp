//
// Created by 20115 on 6/5/2023.
//

#include "Student.h"

string Student::years[4]={"first","second","third","fourth"};
Student::Student(string name, int numSubjects, int year) {
    this->name=name;
    this->numSubjects=numSubjects;
    this->year=year;
    grades=new float[numSubjects];
    for (int i = 0; i <numSubjects; ++i) {
        grades[i]=0;
    }
}

Student::Student(const Student & s1) {
    name=s1.name;
    numSubjects=s1.numSubjects;
    year=s1.year;
    grades=new float[numSubjects];
    for (int i = 0; i <numSubjects; ++i) {
        grades[i]=s1.grades[i];
    }
}

Student::~Student() {
    delete[] grades;
}

string Student::getYear() {
    return years[year-1];
}
float & Student::operator[](int ind)
{
    if(ind<0 ||ind>=numSubjects)
    {
        cout<<"Index error";
        exit(1);
    }
    return grades[ind];

}


Student Student::operator++(int) {
    Student temp= *this;
    if(year<4)
        year++;
    return temp;
}
Student Student::operator--(int) {
    Student temp= *this;
    if(year>0)
        year--;
    return temp;
}

void Student::display() {
    cout<<"name: "<<name<<endl;
    cout<<"year: "<<getYear()<<endl;
    for (int i = 0; i <numSubjects ; ++i) {
        cout<<"\tGrade"<<i+1<<" : "<<grades[i]<<endl;
    }


}
