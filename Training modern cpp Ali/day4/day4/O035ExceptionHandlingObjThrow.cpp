#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"


namespace nm35
{
	class CA
	{
	public:
		virtual void fun()
		{
			cout << "Apple\n";
		}
	};

	class CB :public CA
	{
	public:
		void fun()
		{
			cout << "Orange\n";
		}
	};


	int main()
	{
		int par = 10;
		try
		{
			//CB obCb;
			if (10 == par)
			{
				//throw obCb;
				throw* new CB();
			}
		}
		catch (CB& ob)
		{
			cout << "Palak\n";
			ob.fun();
		}
		//catch (CA ob)
		catch (CA& ob)
		{
			cout << "Bhindi\n";
			ob.fun();
		}
		return 0;
	}

}
