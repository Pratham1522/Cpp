#include<iostream>
#include<variant>
#include<map>
#include<functional>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"

class Product
{
public:
	void ShowAge()
	{
		cout << "Product::ShowAge\n";
	}
};

class Animal
{
public:
	void ShowAge()
	{
		cout << "Animal::ShowAge\n";
	}
};

class Machine
{
public:
	void ShowAge()
	{
		cout << "Machine::ShowAge\n";
	}
};

void DoBusiness(variant<Product, Animal, Machine> vari)
{
	cout << "Business started\n";
	std::visit([](auto obj) {obj.ShowAge(); }, vari);
	cout << "Business completed\n";
	line();
}

int main()
{
	Product prod;
	Animal animal;
	Machine machine;

	DoBusiness(prod);
	DoBusiness(animal);
	DoBusiness(machine);

	return 0;
}