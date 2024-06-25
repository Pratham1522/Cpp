#include<iostream>
#include<cstring>

class Student
{
    int rollno;
    char sname[20];
    int marks[3];
        
    public:
        Student();
        Student(int,const char *,int*);
        void display() const;

        double calculateavg();

        // get and set function
        int getRollno(){  return rollno; }
        char * getSname(){ return sname; }
       
        void setRollno(int r){rollno = r;}
        void setSname(const char *nm){ strcpy(sname,nm); }
        
    
};