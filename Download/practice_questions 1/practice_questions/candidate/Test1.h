#ifndef TEST1
#define TEST1
#include<bits/stdc++.h>
using namespace std;

class Test1{
    public:
    int contestid;
    string dateofexam;
    const int maxmarks=100;
    int markssecured1=0;
    Test1(){}
    void get(){
    }
    void set(int id, string date, int marks){
        this->contestid=id;
        this->dateofexam=date;
        this->markssecured1=marks;
    }
    void accept(){
        int id;
        string date;
        int marks;
        cout<<"enter test 1 id "<<endl;
        cin>>id;
        cout<<"enter date of test 1 "<<endl;
        cin>>date;
        cout<<"enter marks "<<endl;
        try{
            cin>>marks;
            if(marks>100){
                throw marks;
            }
            else{
                set(id,date,marks);
            }
        }
        catch(int marks){
            cout<<"invalid marks "<<endl;
            set(id,date,0);
        }
    }
    friend ostream &operator<<(ostream &out, const Test1 &t){
        out<<"test 1id is "<<t.contestid<<endl;
        out<<"test1 date is "<<t.dateofexam<<endl;
        out<<"test 1 marks is "<<t.markssecured1<<endl;
        return out;
    }
    ~Test1(){}
};

#endif