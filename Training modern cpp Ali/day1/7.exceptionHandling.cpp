#include<iostream>
using std::cout;
#define line cout<<"___________________________\n"
//exception handling is very costly ,always ask if u really want it.
namespace nm6
{
	void fun(int par)
	{
		cout << "Apple\n";
		if (10 == par)
		{
			throw 100;
		}
		cout << "Orange\n";
	}

	int main1()
	{
		cout << "start\n";
		fun(20);
		cout << "Done\n";
		return 0;
	}

	int main2()
	{
		cout << "start\n";
		fun(10);//if exception occur n u dont catch it then program will terminate.
		cout << "Done\n";
		return 0;
	}

	void Kpit_Terminate()
	{
		cout << "Kpit_Terminate\n";
		exit(0);
	}
	int main3()
	{
		std::set_terminate (Kpit_Terminate);//set custom function which will be called on termination of program instead of system termination
		cout << "start\n";
		fun(10);
		cout << "Done\n";
		return 0;
	}

	int main4()
	{
		cout << "start\n";
		try 
		{
			fun(10); //whatever that can give error write in try,play safe
		}
		catch (int exp)
		{
			cout << "Exp : " << exp << '\n'; //if any exception is thrown n match with catch block then catch block will be executed.
		}//there can be multiple catch blocks.
		cout << "Done\n";
		return 0;
	}

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
		}
	};

	int main5()
	{
		int par = 10;
		cout << "start\n";
		try
		{
			CA obj;
			cout << "Apple\n";
			if (10 == par)
			{
				throw 100;
			}
			cout << "Orange\n";
		}//CA::~CA
		catch (int exp)
		{
			cout << "Exp : " << exp << '\n';
		}
		//release catch table
		cout << "Done\n";
		return 0;
	}


	int main6()
	{
		int par = 10;
		cout << "start\n";
		try
		{
			CA obj;//CA::CA
			cout << "Apple\n";
			if (10 == par)
			{
				throw obj;//CA::CA(copy)
			}
			cout << "Orange\n";
		}//CA::~CA
		//catch table : CA::CA(copy)
		catch (CA exp)//CA::CA(copy)
		{
			cout << "CA Exp : " << '\n';
		}//CA::~CA(catch block) 
		// CA::~CA(catch table)
		cout << "Done\n";
		return 0;
	}


	class CB
	{
	public:
		CB()
		{
			cout << "CB ctor\n";
		}
		CB(const CB&)
		{
			cout << "CB Copy\n";
		}
		~CB()
		{
			cout << "CB D-tor\n";
		}
	};


	int main7()
	{
		int par = 10;
		cout << "start\n";
		try
		{
			CB obj;
			cout << "Apple\n";
			if (10 == par)
			{
				throw obj;
			}
			cout << "Orange\n";
		}
		catch (CB exp)
		{
			cout << "CB Exp : " << '\n';
		}
		cout << "Done\n";
		return 0;
	}


	class CC
	{
		static int count;
		int x;
	public:
		CC()
		{
			count++;
			x = count;
			cout << "CC ctor\n";
		}
		CC(const CC&)
		{
			count++;
			x = count;
			cout << "CC Copy\n";
		}
		~CC()
		{
			cout << "CC D-tor x : " << x << '\n';
		}
	};
	int CC::count = 0;

	int main()
	{
		int par = 10;
		cout << "start\n";
		try
		{
			CC obj;//CA1
			cout << "Apple\n";
			if (10 == par)
			{
				throw obj;
			}//~CA1
			cout << "Orange\n";
		}//CA2
		catch (CC exp)//CA3
		{
			cout << "CC Exp : " << '\n';
		}//~CA3 + ~CA2
		cout << "Done\n";
		return 0;
	}
}
