#include<array>
#include<vector>
#include<list>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<numeric>

struct Demo{
    int val;
    Demo(int v) : val(v){}

    friend std::ostream& operator<<(std::ostream& os, const Demo& rhs){
        os<<rhs.val;
        return os;
    }
};

int main(){
    std::array<int,sizeof(int)> arr{10,20};
    // std::cout<<arr.at(3);
    // std::vector<int> v{10,20};
    // v.emplace_back(20);
    // std::cout<<*(++(v.begin()))<<"\n";
    // std::list<int> data {1,2,3,4,5};
    // std::list<int>result;
    // auto itr = std::find_if(data.begin(),data.end(),
    // [](int val){return val%9==0 && val>9/2;});
    // std::cout<<*itr<<"\n";

    // std::list<int> data{1,2,3,4,5};
    // std::list<int>result;
    // std::copy(data.begin(),++data.begin(),result.begin());
    // std::cout<<result.size();

    std::list<int>data{10,2,3,4,5};
    std::vector<int> v{1,2,3};
    std::stack<int> s;
    std::queue<int> q;
    s.push(1);s.push(2);s.push(3);
    q.push(1);q.push(2);q.push(3);

    std::cout<<data.front()<<" "<<data.back()<<"\n";
    std::cout<<v.front()<<" "<<v.back()<<"\n";
    // std::cout<<s.front()<<" "<<s.back()<<"\n";
    std::cout<<q.front()<<" "<<q.back()<<"\n";
}




