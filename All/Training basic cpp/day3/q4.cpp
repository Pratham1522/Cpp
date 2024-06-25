#include<iostream>
using namespace std;

class Empty{

};
int main(){
    cout<<sizeof(Empty);
    return 0;
}
//size is 1 byte as to call a function it should have some size (so != 0),so it give us expected memory class will need when object is initialised. 