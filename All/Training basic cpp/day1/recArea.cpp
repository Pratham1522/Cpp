#include<iostream>

class rectangle{
    private:
    float len,bre;
    float area;

    public:
    rectangle(float l=0,float b=0){
        len=l;
        bre=b;
    }
    void changeLen(float l){
        len=l;
    }
    void changeBre(float b){
        bre=b;
    }
    void getArea(){
        area=len*bre;
        std::cout<<"area of rectangle is "<<area<<"\n";
    }
};
int main(){
    float l;
    float b;
    std::cout<<"Enter the length of rectangle ";
    std::cin>>l;
    std::cout<<"Enter the breadth of rectangle ";
    std::cin>>b;
    rectangle r=rectangle(l,b);
    r.getArea();
    return 0;
}