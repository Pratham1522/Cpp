#include<iostream>
using namespace std;
#define line(msg) cout<<"___________________"msg"____________________\n"
class Rect;
class Polar
{
	double angle;
	double distance;
public:
	Polar(double angle, double distance):angle(angle), distance(distance)
	{
		cout << "1.Polar ctor\n";
	}

	explicit Polar(Rect& rect);
	
	explicit operator Rect() ;
	
	Polar& operator=(const Rect&);
	
	friend ostream& operator<<(ostream& os, const Polar& cmp)
	{
		os << "9.Polar ostream\n";
		return os;
	}
};
class Rect
{
	double x_cor{0.0};
	double y_cor{0.0};
public:
	double getx() const
	{
		return x_cor;
	}
	double gety() const
	{
		return y_cor;
	}
	Rect(double x_cor, double y_cor)
	{

	}
	explicit Rect(Polar& p)
	{
		cout << "2.Rect ctor\n";
	}
	Rect& operator=(const Polar& p)
	{
		cout << "5.Rect assign\n";
		return *this;
	}
	
	explicit operator Polar()
	{
		cout << "7.Rect Conversion\n";
		return Polar(1.0,2.0);
	}
	friend ostream& operator<<(ostream& os, const Rect& cmp)
	{
		os << "8.rect ostream\n";
		return os;
	}
};

Polar& Polar::operator=(const Rect& r)
{
	cout << "3.Polar assign\n";
	r.getx();
	r.gety();
	return *this;
}

 Polar::operator Rect()
{
	 cout << "6.Polar Conversion\n";
	return Rect(1.0, 2.0);
}

Polar::Polar(Rect& rect):angle(rect.getx()),distance(rect.gety())
{
	cout << "4.Polar Ctor\n";
}

int main()
{
	Polar p(90, 100);
	Rect r ( p);
	p = r;
	Polar p1 ( r);
	r = p1;
	r = (Rect)p1;
	p1 = (Polar)r;

	cout << r << p;
	return 0;
}