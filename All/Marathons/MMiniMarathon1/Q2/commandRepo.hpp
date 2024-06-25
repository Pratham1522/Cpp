#include<stack>
#include "command.hpp"
using std::stack;

class CommandRepository      
{
	stack<Command*> repo;

public:
	void Register(Command* cmd) { repo.push(cmd); }

	Command* Retrieve() 
	{
		Command* cmd = repo.top();   //return last command
		repo.pop();
		return cmd;
	}
	
	bool IsEmpty() { return repo.empty(); }
};

