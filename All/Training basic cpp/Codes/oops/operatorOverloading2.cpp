#include <iostream>
class Point
{
    int x, y;

public:
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
    void display()
    {
        std::cout << " \n x=" << x << "  y=" << y;
    }
    Point operator-(Point &pt); // binary-

    Point operator-() // unary -
    {
        // p4-----this
        Point tempobj = *this;
        tempobj.x = -tempobj.x;
        tempobj.y = -tempobj.y;
        return tempobj;
    }
    Point &operator++() // pre increment
    {
        // p6----*this
        ++x;
        ++y;
        return *this; // return p6;
    }
    Point operator++(int) // post increment
    {
        Point tempobj = *this; // 3,4
        x++;
        y++;
        return tempobj;
    }
    Point operator+(int n)
    {
        Point tempobj;
        tempobj.x = this->x + n;
        tempobj.y = y + n;
        return tempobj;
    }

    friend Point operator+(int n, Point &p); // non member function
                                             // friend keyword is requried in declaration of fun but not required in definition

    friend std::ostream& operator<<(std::ostream &os ,const Point &pt)
    {
        os<<pt.x<<" "<<pt.y;
        return os;
    }
};
// :: operator cannot be used  with friend function
Point operator+(int n, Point &p) // non member function
{
    // this pointer is never passed to friend function
    // friend fun can access private data members of class directly
    Point temp;
    temp.x= n + p.x;
    temp.y =n+p.y;
    return temp;
}
Point Point::operator-(Point &pt)
{
    // p1--this ,  p2--pt
    Point sumobj; // local object
    sumobj.x = this->x - pt.x;
    sumobj.y = y - pt.y;
    return sumobj;
}
int main()
{
    // p1==p2
    // p1!=p2

    Point pt3(10,20);
    Point pt4(3,4);
    std::cout<<pt3<<pt4;

    Point p(2, 3);
    Point pt1 = p + 4; // object+constant value--> Userdefineddatatype+builtintype
                       // p.operator+(4)

    Point pt2 = 10 + p; // operator+(10,p)



    // Point p8(3,4);
    // Point p9 = p8++;
    // p8.display();//4  5
    // p9.display();//3  4

    // Point p6(1,2);
    // Point p7=++p6;//p6.operator++()
    // p7.display();//2    3
    // p6.display();//2    3

    // Point p1(2,5),p2(7,1);
    // Point p3= p1-p2; //p1.operator-(p2)
    // p3.display();

    // Point p4(5,8);
    // Point p5=-p4;// p4.operator-()
    // p4.display(); //5  8
    // p5.display(); //-5  -8

    return 0;
}