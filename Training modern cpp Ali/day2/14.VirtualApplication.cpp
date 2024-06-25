#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"
/*
1. yagni -> you arn't gonna need it
2. High cohession
3. SRP -> Single Responsibility Priniciple
*/
namespace nm13
{
	//rejected class (violates SRP)
	class Account
	{
	public:
		void DoDebitSavings(int Accid, int amount)
		{
			cout << "Debit Savings\n";
		}
		void DoDebitCurrent(int Accid, int amount)
		{
			cout << "Debit Current\n";
		}
	};

	int main()
	{
		Account acc;
		acc.DoDebitSavings(101, 100);
		acc.DoDebitCurrent(102, 200);
		return 0;
	}
}
