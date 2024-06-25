#pragma once
#include<iostream>
using std::cout;
using std::ostream;

class CArray
{
    int rowCount = 2;
    int colCount = 3;
    int ar[2][3]={{1,2,3},{4,5,6}};

    public:
    CArray()=default;
    class Helper
    {
        CArray* ptA;
        int index;

        public:
        Helper(CArray* pt1,int index1):ptA(pt1),index(index1)
        {
        
        }

        class Helper2
        {
            CArray* ptB;
            int index1;
            int index2;

            public:
            Helper2(CArray* pt1, int indexA, int indexB):ptB(pt1),index1(indexA),index2(indexB)
            {

            }
            operator int()
            {
                cout<<"reading \n";
                return ptB->ar[index1][index2];
            }
            Helper2& operator = (int val)
            {
                cout << "writing \n";
                (ptB->ar[index1][index2]) = val;
                return *this;
            }
            Helper2& operator = (Helper2 par)
            {
                cout << "read/write \n";
                ptB->ar[index1][index2] = par.ptB->ar[par.index1][par.index2];
                return *this;
            }
        };
        Helper2 operator[](int index1)
        {
            return Helper2(ptA, index, index1);
        }
    };
    Helper operator [] (int index1)
    {
        return Helper(this,index1);
    }
    friend ostream& operator << (ostream& ,const CArray&);

    ~CArray()
    {
    }
};
ostream& operator << (ostream& ot , const CArray& par)
{
    for(int i=0;i<par.rowCount ;i++)
    {
        for(int j=0;j<par.colCount;j++)
        {
            ot << par.ar[i][j] << " ";
        }
        ot << '\n';
    }
    return ot;
}

