#include<iostream>
#include<string>
#include<map>
using namespace std;

namespace nm99
{
	class Approver
	{
		static map<Approver*, Approver*> repo;
		static map<string, bool(*)(int)> condition;
		Approver* successor{ nullptr };
	protected:
		void RequestSuccessor(int amount)
		{
			if (repo.find(this) != repo.end())
			{
				repo[this]->process_loan(amount);
			}
		}
		static bool can_issue_loan(string key, int amount)
		{
			return condition[key](amount);
		}
	public:
		static void Register_Condtions(string key, bool (*fpt)(int))
		{
			condition[key] = fpt;
		}

		void set_successor(Approver* successor)
		{
			//this->successor = successor;
			repo[this] = successor;
		}
		virtual void process_loan(int amount) = 0;
		operator Approver* ()
		{
			return this;
		}
	};
	map<Approver*, Approver*> Approver::repo;
	map<string, bool(*)(int)> Approver::condition;

	class Cashier :public Approver
	{
	public:
		void process_loan(int amount)
		{
			if (can_issue_loan("Cashier", amount))
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
			if (can_issue_loan("Manager", amount))
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
			if (can_issue_loan("Director", amount))
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

	class Dummy
	{
	public:
		Dummy()
		{
			Approver::Register_Condtions("Cashier", [](int amt) {return amt <= 200000; });
			Approver::Register_Condtions("Manager", [](int amt) {return amt <= 400000; });
			Approver::Register_Condtions("Director", [](int amt) {return amt <= 700000; });
		}
	}dummy;

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