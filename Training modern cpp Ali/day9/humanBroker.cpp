#include<iostream>
#include<map>
using namespace std;

class Broker
{
	string m_name;
	double m_charges;
public:
	Broker(string name, double charges):m_name(name), m_charges(charges)
	{
	}
	double get_charges() const
	{
		return m_charges;
	}
	operator string()
	{
		return m_name;
	}
};

class BrokerRepository
{
	static map<string, Broker*> repo;
public:
	static void Register(Broker* broker)
	{
		repo[*broker] = broker;
	}
	static Broker* Retrieve(string broker_name)
	{
		return repo[broker_name];
	}
};
map<string, Broker*> BrokerRepository::repo;

class Dummy
{
public:
	Dummy()
	{
		BrokerRepository::Register(new Broker("BHAMAT", 2000));
		BrokerRepository::Register(new Broker("TelMat", 4000));
		BrokerRepository::Register(new Broker("MarMat", 6000));
		BrokerRepository::Register(new Broker("ShadiMat", 3000));
	}
}dummy;

class Human
{
	int m_id{ 0 };
	string m_name;
	Broker* broker;
public:
	Human(int id,string name,string broker_name)
		:m_id(id),m_name(name),broker(BrokerRepository::Retrieve(broker_name))
	{
	}
	double get_charges()
	{
		return broker->get_charges();
	}
	string broker_name()
	{
		return *broker;
	}
	int get_id()
	{
		return m_id;
	}
	string get_name()
	{
		return m_name;
	}
};

class Transaction
{
	 map<int, Human*> repo;
public:
	void Subcribe(Human *human)
	{
		repo[human->get_id()] = human;
	}
	void Unsubscribe(int id)
	{
		delete repo[id];
		repo.erase(id);
	}
	void List()
	{
		for (auto rng : repo)
		{
			Human* human = rng.second;
			cout << human->get_id() << '\t' << human->get_name() << '\t' << human->broker_name() << '\t' << human->get_charges() << '\n';
		}
	}

	void List(string bName)
	{
		for (auto rng : repo)
		{
			Human* human = rng.second;
			if (human->broker_name() == bName)
			{
				cout << human->get_id() << '\t' << human->get_name() << '\t' << human->broker_name() << '\t' << human->get_charges() << '\n';
			}
		}
	}
};

//-------------------------------------

int main()
{
	Transaction trans;
	trans.Subcribe(new Human(101, "shubam", "TelMat"));
	trans.Subcribe(new Human(102, "kunal", "BHAMAT"));
	trans.Subcribe(new Human(103, "aabash", "ShadiMat"));
	trans.Subcribe(new Human(104, "Nishu", "MarMat"));
	trans.Subcribe(new Human(105, "Vishal", "TelMat"));
	trans.Subcribe(new Human(106, "Aman", "BHAMAT"));
	trans.Subcribe(new Human(107, "Rohan", "TelMat"));
	trans.Subcribe(new Human(108, "Vedanth", "MarMat"));


	trans.List();
	cout << "__________________________________\n";
	trans.Unsubscribe(104);
	trans.List();
	cout << "__________________________________\n";
	trans.List("TelMat");
	return 0;
}
