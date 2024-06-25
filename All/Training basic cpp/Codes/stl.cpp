#include<iostream>
#include<vector>
#include<algorithm>
/*
STL : standard template library


*/

int main()
{
    std::vector<int>  v1;
    v1.push_back(10);
    v1.push_back(38);
    v1.push_back(20);
    v1.push_back(44);
     v1.push_back(38);
    v1.push_back(22);
    v1.push_back(11);
     v1.push_back(3);
    v1.push_back(20);
    v1.push_back(44);

    sort( v1.begin() ,v1.end() );

    std::vector<int>::iterator it = v1.begin();
    while( it!= v1.end())
    {
        std::cout<<*it<<"  ";
        it++;
    }



    for(int i=0;i< v1.size(); i++)
        std::cout<<v1[i]<<"  ";

   // v1.clear();

    if(v1.empty())
        std::cout<<"\n vector is empty";
    else
        std::cout<<"\n vector is not empty";

    std::vector<int> v2;
    if(v1==v2)
        std::cout<<"\n vectors are same";
    else
        std::cout<<"\n vector is not same";

    

    return 0;
}