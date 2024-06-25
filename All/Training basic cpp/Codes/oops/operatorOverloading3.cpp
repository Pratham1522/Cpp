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
    ~Point()
    {
        std::cout<<"\n ~Point() called ";
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

class Helper
{    Point *ptr;
    public  :
        Helper()
        {
            ptr=new Point();
        }
        Helper(int a,int b)
        {
            ptr=new Point(a,b);
        }
        ~Helper()
        {
            delete ptr;
        }
        Point *operator->()
        {
            return ptr;
        }
        Point& operator*()
        {
            return *ptr;
        }
};
int main()
{
    Helper obj;
    (*obj).display();

    obj->display();


    return 0;
}