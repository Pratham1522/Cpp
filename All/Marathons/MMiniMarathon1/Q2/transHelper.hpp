#include "commandRepo.hpp"

class TransHelper   
{
	Account& acc;
	CommandRepository repository;

public:
	TransHelper(Account& acc):acc(acc){}  //constructor set account

	double getBalance() const { return acc.getBalance(); }
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
        cout<<"Undo performed ...\n";
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