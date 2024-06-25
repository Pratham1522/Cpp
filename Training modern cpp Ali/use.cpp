#include <iostream>
using std::cout;

void print(int** arr)
{
    for (int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    int** arr = new int*[2];
    for(int i=0;i<2;i++)
        arr[i]= new int[3];

    for (int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            arr[i][j] = i+j;
        }
    }

   print(arr); 

    return 0;
}
