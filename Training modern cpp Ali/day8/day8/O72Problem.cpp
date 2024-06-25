#include<iostream>
#include<map>
using namespace std;
#define line(msg) cout<<"____________________"#msg"______________________\n"
namespace nm72
{
	class Employee
	{
	public:
		virtual void DoJob() = 0;
	};
	class Develper :public Employee//10
	{
	public:
		Develper()
		{
			cout << "Developer\n";
		}
		void DoJob() override
		{
			cout << "Developer : DoJob\v";
		}
	};

	class Manager :public Employee//20
	{
	public:
		Manager()
		{
			cout << "Manager\n";
		}
		void DoJob() override
		{
			cout << "Manager : DoJob\v";
		}
	};

	class Tester :public Employee//30
	{
	public:
		Tester()
		{
			cout << "Tester\n";
		}
		void DoJob() override
		{
			cout << "Tester : DoJob\v";
		}
	};
	using FPTR = Employee * (*)();
	class Repository
	{
		static map<int, FPTR> repo;
	public:
		static void Register(int key, FPTR fp)
		{
			repo[key] = fp;
		}
		static Employee* GetEmp(int key)
		{
			//return repo[key]();
			FPTR fp = repo[key];
			Employee* emp = fp();
			return emp;
		}
	};
	map<int, FPTR> Repository::repo;

	class Dummy
	{
	public:
		Dummy()
		{
			Repository::Register(10, []()->Employee* {return new Develper(); });
			Repository::Register(20, []()->Employee* {return new Manager(); });
			Repository::Register(30, []()->Employee* {return new Tester(); });
		}
	}dummy;
	Employee* Factory(int par)
	{
		return Repository::GetEmp(par);
	}
	int main()
	{
		Employee* emp = Factory(30);
		emp->DoJob();
		return 0;
	}
}