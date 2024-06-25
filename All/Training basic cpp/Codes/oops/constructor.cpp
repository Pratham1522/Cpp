#include<iostream>
#include<cstring>
class Student
{
    private:
	    int rollno;
	    char sname[20];
	    int marks;
    public:
        Student()//default constructor
        {
            rollno=1;
            strcpy(sname,"John");
            marks=77;
        }
        Student(int r,const char *name,int mk)//parameterized ctor
        {
            rollno = r;
            strcpy(sname,name);
            marks=mk;
        }
    
        void display()
        {
            std::cout<<"\n Rollno = "<<rollno<<" name ="<<sname<<" marks= "<<marks;
        }
};
void print(char* name){
    std::cout << "\n\t" << name << " is called." ;
}
int main()
{
    Student s1;// s1 is an object of Student class/ instance of a class
    /*
    whenever object is created
      - memory is allocated
      - constructor is called
      - data members are initialized
    */

    s1.display();
    Student s2(2,"Rahul",88);
    s2.display();
    
    char* s=new char[20];
    std::cin>>s;
    print(s);

    return 0;
}
