#ifndef CANDIDATE
#define CANDIDATE
#include<bits/stdc++.h>
#include "Test1.h"
#include "Test2.h"
using namespace  std;
enum jobapplied{clerk,manager,engineer};

class Candidate : public Test1, public Test2{
    public:
    string candidatename;
    int candidateid;
    string desig;
    Test1 t1;
    Test2 t2;
    Candidate(){}
    Candidate(string name, int id){}
    Candidate(const Candidate &a){}
    void set(string name, int id){
        this->candidateid=id;
        this->candidatename=name;
    }
    void get(){}
    void accept(){
        int id;
        string name;
        cout<<"enter name "<<endl;
        cin>>name;
        cout<<"enter id "<<endl;
        cin>>id;
        t1.accept();
        t2.accept();
        set(name,id);
    }
    void check(){
        if(t1.markssecured1>70 && t2.markssecured2>150){
            cout<<"secured your rank successfully"<<endl;
        }
        else{
            cout<<"fail"<<endl;
        }
    }
    friend ostream& operator<<(ostream& out, const Candidate &c){
        out<<"\ncandidate id is "<<c.candidateid<<endl;
        out<<"candidate name is "<<c.candidatename<<endl;
        out<<"candidate designation is "<<c.desig<<endl;
        cout<<c.t1;
        cout<<c.t2;
        return out;
    }
    friend istream &operator>>(istream &in, Candidate &e){
        string input;
        cout<<"enter designation(clerk, man, engg) ";
        in>>input;
        enum jobapplied d1=jobapplied(clerk);
        if(input=="clerk"){
            d1=jobapplied{clerk};
        }
        else if(input=="man"){
            d1=jobapplied{manager};
        }
        else if(input=="engg"){
            d1=jobapplied{engineer};
        }
        else{
            cout<<"wrong selecetion, clerk is edfault"<<endl;
        }
        switch (d1){
            case 0:
            e.desig="clerk";
            break;
            case 1:
            e.desig="manager";
            break;
            case2:
            e.desig="engineer";
            break;
        }
        return in;
    }
    ~Candidate(){}
};

#endif