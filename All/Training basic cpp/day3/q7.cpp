#include<iostream>
using namespace std;

// class A{
//     A(){   //watch out for private.
//         cout<<"A Constructor called \n";
//     }
// };

// int main(int argc, char const *argv[]){
//     A a;
//     return 0;
// }

class ex
{
private:
int i; double j;

public :

ex(int ii=0, double jj=0.0)
{

i = ii; j = jj;
}
void display()
{
cout << i << j;
}
};
int main(){
ex e1;
e1 = ex(10 ,2.9);
e1.display( );
}