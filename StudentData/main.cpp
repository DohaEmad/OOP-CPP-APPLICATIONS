#include <iostream>
#include "Student.h"
int main() {
    Student s("doha",5,2);
    s[0]=100; s[1]=90; s[2]=80;s[3]=77;s[4]=88;
    Student s2=s++;
    cout<<"---------------first student------------------"<<endl;
    s.display();
    cout<<"---------------second student------------------"<<endl;
    s2.display();
    return 0;
}
