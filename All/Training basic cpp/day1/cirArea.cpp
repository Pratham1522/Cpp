#include <iostream>
#include <cmath>
class circleArea{
    private:
    float radius=0;
    float area=0;

    public:
    circleArea(int r=0){
        radius=r;
    }
    void getArea(){
        area=M_PI * (radius * radius);
        std::cout<<"Area of circle with radius "<<radius<<" is : "<<area<<"\n";
    }


};

int main(){
    float r;
    std::cout<<"Enter the radius of circle ";
    std::cin>>r;
    circleArea c=circleArea(r);
    c.getArea();
}