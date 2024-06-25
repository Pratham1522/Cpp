#include<iostream>
using std::cout;
using std::ostream;
#define line(msg) cout<<"*------------------- "#msg" ---------------------*\n";

class cArray
{ 
    int size;
    int* arr;

    public:
    cArray(int par):size(par),arr(new int[size])
    {
        for(int i=0;i<size;i++)
        {
            arr[i]=10*(i+1);
        }
    }
    class Element
    {
        cArray* pt;
        int index;

        public:
        Element(cArray* pt,int index):pt(pt),index(index)
        {

        }
        operator int()
        {
            cout << "Reading \n";
            return pt->arr[index];
        }
        Element& operator=(int val){
            cout<<"Writing \n";
            pt->arr[index] = val;
            return *this;
        }
        Element& operator=(Element par){
            cout<<"Reading + Writing \n";
            pt->arr[index] = par.pt->arr[index];
            return *this;
        }
    };
    Element operator[](int index)
    {
        return Element(this,index);
    }
    friend ostream& operator << (ostream &out, const cArray &obj);
    ~cArray()
    {
        delete[] arr;
    }
};
ostream& operator << (ostream &out, const cArray &obj){
    for(int i=0;i<obj.size;i++){
        out<< "arr[" <<i<<"]="<<obj.arr[i]<<"\n";
    }
    return out;
}
int main()
{
    line(welcome);

    cArray obj(5);
    int k =obj[1]; //read
    obj[0]=9; //write
    obj[1]=obj[0]; //read+write
    cout<<obj ;
    line(end);
    return 0;
}  