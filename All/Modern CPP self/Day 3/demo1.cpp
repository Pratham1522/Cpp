#include <iostream>
using std::cout;
using std::ostream;
#define line() cout<<"---------------------------------";

class Helper
{
    CArray* pt;
    int index;

    public:
    Helper(int i,CArray* pt):pt(pt),index(i) 
    {       
    }
    operator int()
    {
        cout << "reading\n";
        return pt->arr[index];
    }
    Element& operator =(int val)
    {
        cout<<"writing\n";
        pt
    }

};
class CArray
{
    int size;
    int *arr;

public:
    CArray(int par):size(par),arr(new int [size]){
        arr[0]=10;
        arr[1]=20;
        arr[2]=30;
        arr[3]=40;
        arr[4]=50;
    }  
    int& operator [](int index)
    {
        return arr[index];
    }  
    ~CArray()
    {
        delete[] arr;
    }
    friend ostream& operator<<(ostream &out, const CArray &obj);  //friend function declaration
};
ostream& operator<<(ostream &out, const CArray &obj)
{
    for(int i=0;i<obj.size;i++)
    {
        out << "arr[" << i << "]=" << obj.arr[i] <<"\n";
    }
    return out;
}
int main()
{
    CArray obArr(5);
    int k=obArr[1];
    obArr[0]=999;
    obArr[1]=obArr[0];
    cout<<obArr<<"k="<<k<<"\n";
    return 0;
}
//nested classses are automatically friend of outer class.
//book : Effective cpp 