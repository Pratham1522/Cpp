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

namespace nm15
{
	//Rejected class(violates Dry) 
	class SavingsAccount
	{
	public:
		void DoDebitSavings(int Accid, int amount)
		{
			cout << "Open DB\n";
			cout << "Debit Savings\n";
			cout << "Close DB\n";
		}
	};

	class CurrentAccount
	{
	public:
		void DoDebitCurrent(int Accid, int amount)
		{
			cout << "Open DB\n";
			cout << "Debit Current\n";
			cout << "Close DB\n";
		}
	};

	int main()
	{
		SavingsAccount sa;
		sa.DoDebitSavings(101, 100);
		line();
		CurrentAccount cu;
		cu.DoDebitCurrent(102, 200);
		return 0;
	}
}