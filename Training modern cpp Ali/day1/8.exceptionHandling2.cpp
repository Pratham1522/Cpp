#include<iostream>
using std::cout;
#define line cout<<"___________________________\n"


class CA
{
public:
	CA()
	{
		cout << "CA ctor\n";
	}
	~CA()
	{
		cout << "CA D-tor\n";
		//throw 200; //never do this
	}
};



int main1()
{
	int par = 10;
	cout << "start\n";
	try
	{
		try
		{
			CA obj; //CA
			cout << "Apple\n";
			if (10 == par)
			{
				throw 100;
			}
			cout << "Orange\n";
		}//~CA
		// catch (int& exp)
        // {
		// 	exp += 100;  //can do ,exp=200
		// 	cout << "inner int Exp : "<<exp << '\n';
		// 	// throw 200;//replace , will throw 200.
		// 	// throw exp;//replace , will throw the changed exp
		// 	throw;//rethrow // will throw 200
		// }
		catch (int exp)
		{
			// exp += 100;  //can do ,exp=200
			cout << "inner int Exp : "<<exp << '\n';
			// throw 200;//replace , will throw 200.
			// throw exp;//replace , will throw the changed exp
			// throw;//rethrow //with only catch(int exp) will throw 100 only will not modify the value in catch table.
		}
		cout << "Apricot\n";
	}
	catch (int exp)
	{
			cout << "outer int Exp : "<<exp << '\n';
	}
	cout << "Done\n";
	return 0;
}


int main2()
{
	int par = 10;
	cout << "start\n";
	
		try
		{
			CA* pt = new CA(); // if throw from constructor then after this line move to catch block.

			cout << "Orange\n";
			delete pt;
		}
		catch (int exp)
		{
			cout << "inner int Exp : " << exp << '\n';
		}
		
	cout << "Done\n";
	return 0;
}


class Cat
{
public:
	Cat()
	{
		cout << "Cat ctor\n";
	}
	~Cat()
	{
		cout << "Cat D-tor\n";
	}
};


class CBase
{
public:
	CBase()
	{
		cout << "CBase ctor\n";
	}
	~CBase()
	{
		cout << "CBase D-tor\n";
	}
};

class CB:public CBase
{
	Cat cat;
public:
//first base, then contained ,then this class const call
	CB()
	{
		cout << "CB ctor\n";
		throw 200;
	}
	~CB()
	{
		cout << "CB D-tor\n";
	}
};

int main1()
{
	int par = 10;
	cout << "start\n";
	try
	{
		CB obj;
	}//no CB destructor,where CBase and CAt destructor
	catch (int exp)
	{
		cout << "inner int Exp : " << exp << '\n';
	}
	cout << "Done\n";
	return 0;
}
