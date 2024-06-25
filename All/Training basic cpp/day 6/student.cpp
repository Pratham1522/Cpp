#include<iostream>
using namespace std;

class Student{
    string name;
    int roll_no;
    float marks[5];

    public:
    Student(){
        name="*";
        roll_no=0;
        for(int i=0;i<5;i++){
            marks[i]=0.0;
        }
    }
    Student(string sName,int rno,float sMarks[]){
        name=sName;
        roll_no=rno;
        for(int i=0;i<5;i++){
            marks[i]=sMarks[i];
        }
    }
    void display(){
        cout<<"name : "<<name<<"\n";
        cout<<"roll_no : "<<roll_no<<"\n";
        // cout<<marks<<"\n";
        cout<<"Marks : {";
        for(int i=0;i<5;i++){
            cout<<marks[i]<<" ";
        }
        cout<<"} \n";
    }
    explicit Student(const Student &obj){    //compulsary needed const 
        name=obj.name;
        roll_no=obj.roll_no;
        for(int i=0;i<5;i++){
            marks[i]=obj.marks[i];
        }
    }
    void calculate_grade(){
        float grade=0;
        for(int i=0;i<5;i++){
            grade+=marks[i];
        }
        cout<<"Grade is : "<<(grade/5)<<"\n";
    }
};
//name=new char[50];    also delete in destructor
//rule of 4
//strcpy
int main(){
    float marks[5]={1.1,1.1,3.3,1.1,2.2};
    // cout<<marks<<"\n";
    Student obj("prashant",34,marks);
    Student obj1(obj);
    // obj.display();
    obj1.display();
    obj1.calculate_grade();
    return 0;
}