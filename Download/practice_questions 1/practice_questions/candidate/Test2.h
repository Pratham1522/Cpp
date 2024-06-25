#ifndef TEST2
#define TEST2
#include<bits/stdc++.h>
using namespace std;

class Test2{
    public:
    int contestid;
    string dateofexam;
    const int maxmarks=100;
    int markssecured2=0;
    Test2(){}
    void get(){
    }
    void set(int id, string date, int marks){
        this->contestid=id;
        this->dateofexam=date;
        this->markssecured2=marks;
    }
    void accept(){
        int id;
        string date;
        int marks;
        cout<<"enter test 2 id "<<endl;
        cin>>id;
        cout<<"enter date of test 2 "<<endl;
        cin>>date;
        cout<<"enter marks "<<endl;
        try{
            cin>>marks;
            if(marks>200){
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
    friend ostream &operator<<(ostream &out, const Test2 &t){
        out<<"test 2 id is "<<t.contestid<<endl;
        out<<"test 2 date is "<<t.dateofexam<<endl;
        out<<"test 2 marks is "<<t.markssecured2<<endl;
        return out;
    }
    ~Test2(){}
};

#endif