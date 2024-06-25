#include<bits/stdc++.h>
#include "candidate.h"
using namespace std;

int main(){
    Candidate c[3];
    for(int i=0;i<3;i++){
        cout<<i+1<<"."<<endl;
        c[i].accept();
        cin>>c[i];
    }
    for(int i=0;i<3;i++){
        cout<<c[i];
        c[i].check();
    }
    return 0;
}