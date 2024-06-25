#include<iostream>
#include<stack>
using namespace std;
#define line(msg) cout<<"____________________"#msg"______________________\n"
/*
Create Account class which takes state as AccId and InitialAmount.
with behaviors getbalance,debit and credit.

Create a transaction helper class to wrap all account behaviors.
Add another behavior to perform undo operations

create debit and credit command classes to perform appropriate command operations like
execute and unexceute and also maintain the command state to 
perform operatrions on account object.

Extend Debit and credit command classes from base class command comprising execute , unexecute and state

All operattions done should be through commmad objects in transaction helper


create a repository to maintain a stack of commands and allow register and retrieval of command

store command objects in the repository after vevery operation;

retrieve command from repository on every undo and call its unexecute

Do the appropraite cleanup of commands in transaction helper


*/



class Account
{
	int m_accId{0};
	double m_balance{0};
public:
	Account(int id,double amount):m_accId(id), m_balance(amount)
	{
	}
	double getBalance() const
	{
		return m_balance;
	}
	void debit(double amount)
	{
		m_balance -= amount;
	}
	void credit(double amount)
	{
		m_balance += amount;
	}
};

class Command
{
protected:
	double amount{0};
	Command(double amount):amount(amount)
	{
	}
public:
	virtual void execute(Account&) = 0;
	virtual void unexecute(Account&) = 0;
	virtual ~Command() = default;
};

class DebitCommand :public Command
{
public:
	DebitCommand(double amount) :Command(amount)
	{
	}
	void execute(Account& acc) override
	{
		acc.debit(amount);
	}
	void unexecute(Account& acc) override
	{
		acc.credit(amount);
	}
};

class CreditCommand :public Command
{
public:
	CreditCommand(double amount) :Command(amount)
	{
	}
	void execute(Account& acc) override
	{
		acc.credit(amount);
	}
	void unexecute(Account& acc) override
	{
		acc.debit(amount);
	}
};

class CommandRepository
{
	stack<Command*> repo;
public:
	void Register(Command* cmd)
	{
		repo.push(cmd);
	}
	Command* Retrieve()
	{
		Command* cmd = repo.top();
		repo.pop();
		return cmd;
	}
	bool IsEmpty()
	{
		return repo.empty();
	}
};


class TransHelper
{
	Account& acc;
	CommandRepository repository;
public:
	TransHelper(Account& acc):acc(acc)
	{
	}
	double getBalance() const
	{
		return acc.getBalance();
	}
	void debit(double amount)
	{
		DebitCommand* cmd = new DebitCommand(amount);
		cmd->execute(acc);
		repository.Register(cmd);
	}
	void credit(double amount)
	{
		CreditCommand* cmd = new CreditCommand(amount);
		cmd->execute(acc);
		repository.Register(cmd);
	}
	void undo()
	{
		Command* cmd = repository.Retrieve();
		cmd->unexecute(acc);
		delete cmd;
	}
	~TransHelper()
	{
		while (!repository.IsEmpty())
		{
			Command* cmd = repository.Retrieve();
			delete cmd;
		}
	}
};

int main()
{
	Account acc(101, 10000);
	TransHelper trans(acc);
	trans.credit(1000);
	trans.credit(2000);
	trans.credit(4000);

	cout << "balance : " << trans.getBalance() << '\n';//17000
	trans.debit(1000);
	trans.debit(2000);
	cout << "balance : " << trans.getBalance() << '\n';//14000
	trans.undo();
	trans.undo();
	trans.undo();
	cout << "balance : " << trans.getBalance() << '\n';//13000
	return 0;
}