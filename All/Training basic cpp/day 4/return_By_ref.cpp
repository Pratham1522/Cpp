#include<iostream>
using namespace std;

int& max(int &a,int &b){
    if(a<b){
        return b;
    }
    return a;
}
int main(){
    int a=7,b=3;
    cout<<max(a,b)<<"\n";
}