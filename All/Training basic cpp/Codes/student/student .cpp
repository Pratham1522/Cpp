#include "student.h"
#include<cstring>
/*
return_type classname::functionname(){  }
*/

double Student::calculateavg()
{
    int sum=0;
    for(int i=0;i<3;i++)
    {
        sum+=marks[i];
    }
    return sum/3.0;
}

Student::Student():rollno(1)
{
    std::cout<<"\n Student() called ";   
    strcpy(sname, "John");   
}
Student::Student(int r, const char *name, int *m)
{
    // data member
    // parameter-local variable- within a block

    rollno = r;
    strcpy(sname, name);
    for(int i=0;i<3;i++)
        marks[i]=m[i];
   
}
void Student::display()const
{
    std::cout << "\n Rollno = " << rollno << " name =" << sname ;
    for(int i=0;i<3;i++)
        std::cout<< " marks= " << marks[i];
}