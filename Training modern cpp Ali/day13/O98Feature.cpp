#include<iostream>
#include<string>
using namespace std;

namespace nm98
{
	class Approver
	{
		Approver* successor{ nullptr };
	protected:
		void RequestSuccessor(int amount)
		{
			if (successor != nullptr)
			{
				successor->process_loan(amount);
			}
		}
	public:
		void set_successor(Approver* successor)
		{
			this->successor = successor;
		}
		virtual void process_loan(int amount) = 0;
		operator Approver* ()
		{
			return this;
		}
	};

	class Cashier :public Approver
	{
	public:
		void process_loan(int amount)
		{
			if (amount <= 200000)
			{
				cout << "Loan processed by cashier " << amount << '\n';
			}
			else
			{
				cout << "Loan Cannot be processed by Cashier " << amount << '\n';
				RequestSuccessor(amount);
			}
		}
	};

	class Manager :public Approver
	{
	public:
		void process_loan(int amount)
		{
			if (amount <= 400000)
			{
				cout << "Loan processed by Manager " << amount << '\n';
			}
			else
			{
				cout << "Loan Cannot be processed by Manager " << amount << '\n';
				RequestSuccessor(amount);
			}
		}
	};


	class Director :public Approver
	{
	public:
		void process_loan(int amount)
		{
			if (amount <= 700000)
			{
				cout << "Loan processed by Director " << amount << '\n';
			}
			else
			{
				cout << "Loan Cannot be processed by Director " << amount << '\n';
				RequestSuccessor(amount);
			}
		}
	};


	void RequestLoan(int amount, Approver& approver)
	{
		approver.process_loan(amount);
	}

	int main()
	{
		Cashier john;
		Manager james;
		Director cliff;

		john.set_successor(james);
		james.set_successor(cliff);

		RequestLoan(150000, john);
		cout << "___________________________________\n";
		RequestLoan(250000, john);
		cout << "___________________________________\n";
		RequestLoan(450000, john);
		cout << "___________________________________\n";
		RequestLoan(750000, john);

		return 0;
	}
}