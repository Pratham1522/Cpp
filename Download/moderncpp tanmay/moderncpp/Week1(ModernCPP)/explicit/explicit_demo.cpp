#include <iostream>

class eg{
    public:
        virtual void solve(){std::cout<<"eg";}
};

class Demo 
{
private:
    int _id;
    std::string _name;
public:
    explicit Demo(int id):_id{id}{}
    explicit Demo(int id,std::string name="xyz"):_id{id},_name{name}{}
    ~Demo()=default;
    virtual void solve() final{std::cout<<"demo";}
};

class fancy : public Demo{
    private:
        std::string _tag_for_demo;
    public:
      //  fancy(){}
};

// void Magic(Demo obj){

// }

int main(){
    //Magic(10);
    Demo d(1,"abc");
    d.solve();
}
