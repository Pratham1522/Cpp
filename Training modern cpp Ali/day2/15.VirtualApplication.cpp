#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"
/*
1. yagni -> you arn't gonna need it
2. High cohession
3. SRP -> Single Responsibility Priniciple
4. Kiss -> keep it simple and stupid

*/
namespace nm14
{
	//Approved class 
	class SavingsAccount
	{
	public:
		void DoDebitSavings(int Accid, int amount)
		{
			cout << "Debit Savings\n";
		}
	};

	class CurrentAccount
	{
	public:
		void DoDebitCurrent(int Accid, int amount)
		{
			cout << "Debit Current\n";
		}
	};

	int main()
	{
		SavingsAccount sa;
		sa.DoDebitSavings(101, 100);
		CurrentAccount cu;
		cu.DoDebitCurrent(102, 200);
		return 0;
	}
}