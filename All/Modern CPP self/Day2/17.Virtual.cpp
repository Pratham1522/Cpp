#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"
/*
1. yagni -> you arn't gonna need it
2. High cohession
3. SRP -> Single Responsibility Priniciple
4. Kiss -> keep it simple and stupid
5. Dry/Die/Wet/Oaoo -> dont repeat yourself/duplication is evil/We Enjoy typing/Once and only once
*/

namespace nm16
{
	//template method pattern
	//Approved class
	class Account
	{
	protected:
		virtual void ActualDebit(int Accid, int amount) = 0;
		/*{
			cout << "Actual Debit Account\n";
		}*/

	public:
		void Debit(int Accid, int amount)
		{
			cout << "Open DB\n";
			ActualDebit(Accid, amount);
			cout << "Close DB\n";
		}
	};

	class SavingsAccount :public Account
	{
	protected:
		void ActualDebit(int Accid, int amount) override
		{
			cout << "Debit Savings\n";
			//Account::ActualDebit(Accid, amount);
		}
	};

	class CurrentAccount :public Account
	{
	protected:
		void ActualDebit(int Accid, int amount) override
		{
			cout << "Debit Current\n";
		}
	};

	int main()
	{
		SavingsAccount sa;
		sa.Debit(101, 100);
		line();
		CurrentAccount cu;
		cu.Debit(102, 200);
		return 0;
	}
}