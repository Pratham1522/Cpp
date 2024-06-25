#include<iostream>
#include<functional>
#include<map>
using namespace std;
#define line(msg) cout<<"___________________"#msg"____________________\n"

class IMomento
{
public:
	virtual void hydetrate() = 0;
	virtual void dehydetrate() = 0;
};

class CareTaker
{
	map<void*, IMomento*> repo;
public:
	operator CareTaker* ()
	{
		return this;
	}
	void Store(void* key,IMomento*value)
	{
		repo[key] = value;
	}
	IMomento* Retrieve(void* key)
	{
		IMomento* value = repo[key];
		repo.erase(key);
		return value;
	}
};

class BaseMomento :public IMomento
{
	CareTaker* caretaker{ nullptr };
public:
	void SetCareTaker(CareTaker* caretaker)
	{
		this->caretaker = caretaker;
	}
	void hydetrate() override
	{
		IMomento* state=clone();
		caretaker->Store(this, state);
	}
	void dehydetrate() override {
		IMomento* recievedSatate = caretaker->Retrieve(this);
		recieveState(recievedSatate);
	}
protected:
	virtual IMomento* clone() = 0;
	virtual void recieveState(IMomento* ) = 0;
};

class CProduct:public BaseMomento
{
public:
	int category;
	string name;
	double price;
	CProduct() = default;
	CProduct(int category,string name,double price):category(category), name(name), price(price)
	{
	}
	void Display()
	{
		cout << category<<"____________"<< name << "_________" << price << '\n';
	}
protected:
	IMomento* clone() override
	{
		return new CProduct(category, name, price);
	}
	void recieveState(IMomento* recieveSatate) override
	{
		CProduct* cp = dynamic_cast<CProduct*>(recieveSatate);
		if (nullptr != cp)
		{
			this->category = cp->category;
			this->name = cp->name;
			this->price = cp->price;
		}
	}
};

class CEmployee :public BaseMomento
{
public:
	int id;
	string ename;
	string dept;
	CEmployee() = default;
	CEmployee(int id,string ename,string dept):id(id),ename(ename),dept(dept)
	{
	}
	void Display()
	{
		cout << id << "_________" << ename << "______________" << dept << '\n';
	}
protected:
	IMomento* clone() override
	{
		return new CEmployee(id, ename, dept);
	}
	void recieveState(IMomento* recieveSatate) override
	{
		CEmployee* ce = dynamic_cast<CEmployee*>(recieveSatate);
		if (nullptr != ce)
		{
			this->id = ce->id;
			this->ename = ce->ename;
			this->dept = ce->dept;
		}
	}
};

int main()
{
	CareTaker c1, c2;
	CProduct cp1(101, "nail polish", 150);
	CEmployee e1(101, "sachi", "batsman");
	line(BeforeCache);
	cp1.Display();
	e1.Display();
	line(Cache);
	cp1.SetCareTaker(c1);
	e1.SetCareTaker(c1);
	cp1.hydetrate();
	e1.hydetrate();
	line(AfterChange);
	cp1.name = "face polish";
	cp1.price = 301;
	e1.dept = "AllRounder";
	cp1.Display();
	e1.Display();
	line(RetriveCache);
	cp1.dehydetrate();
	e1.dehydetrate();
	cp1.Display();
	e1.Display();
	return 0;
}