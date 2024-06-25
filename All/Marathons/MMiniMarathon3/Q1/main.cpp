#include "CArray.hpp"
#define line() cout<<"-----------------------------\n"

void Start(CArray& arr)
{
    int x = arr[1][2];
    //read operation : reading
    arr[0][1] = 78 ;
    //write ooperation : writing
    arr[1][1] = arr[0][1];
    line();
    //both : read/write.
    cout << arr << '\n' << "x = "<< x << '\n';
    line();
};
int main()
{
    CArray arr;
    Start(arr);
    return 0;
}
