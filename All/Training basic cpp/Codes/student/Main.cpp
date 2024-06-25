#include "student.h"
void showavg(Student *s[],int size)
{
    double avg[size];
      for(int i=0;i<size;i++)
        avg[i]=s[i]->calculateavg();
          //std::cout<<"\n avg = "<<s[i]->calculateavg();

    double max=avg[0];
    for(int i=0;i<size;i++)
    {
        if(max< avg[i] )
            max=avg[i];
    }    
    std::cout<<"\n max avg = "<<max;
}
// search for given student based on rollno
bool search(Student *s[],int size,int r)
{   
     for(int i=0;i<size;i++)
     {
        if(s[i]->getRollno() ==r )
            return true;
        
     }
    return false;

}

int main()
{    

    int m1[]={44,55,66};
    int m2[]={42,65,64};
    int m3[]={40,35,67};
    Student *s[3];
     s[0] = new Student(101,"Jay",m1);
     s[1] = new Student(102,"Hari",m2);
     s[2] = new Student(103,"Soham",m3);

     bool flag=search(s,3,102);
     if(flag)
        std::cout<<"\n Student found ";
    else
        std::cout<<"\n Not found ";

     showavg(s,3);

   

     // calculate avg marks


    // constant objects can invoke/call constant functions only
    // const Student st;
    // st.display();

    // //non constant objects can invoke/call any functions
    // Student *s[3];
    // s[0] = new Student(101,"Jay",88);
    // s[1] = new Student(102,"Hari",95);
    // s[2] = new Student(103,"Soham",66);
    // for(int i=0;i<3;i++)
    //     s[i]->display();

   // []   ()  ++  --   unary-  !   *   & 

    // Student sarr[3]={{501,"Neha",66},{502,"Teena",78},{503,"Yash",90}};
    // for(int i=0;i<3;i++)
    //     sarr[i].display();

    // Student s1; // s1 is an object of Student class/ instance of a class
    // s1.display();
    // Student s2(2, "Rahul", 30);
    // s2.display();
    // s2.setMarks(70);
    // std::cout<<"\n New marks = "<<s2.getMarks()<<std::endl;
    // // int *p = malloc(10*sizeof(int));
    // // int *p1 = new int[10];
    // Student *sptr  = new Student;
    // sptr->display();

    // delete sptr; //to avoid memory leakage 

    return 0;
}