#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"

	class CA
	{
	public:
		CA()//setvptr(CA::Vftable)
		{
		}
		void DoJob()
		{
			//this->Apple(); //this->vptr->vtable[0]();
			Apple();
		}
		virtual void Apple()
		{
			cout << "CA::Apple Ooty\n";
		}
		~CA()
		{//setvptr(CA::Vftable)
		}
	};
	class CB :public CA
	{
	public:
		CB()//1) CA::CA() , setvptr(CB::Vftable)
		{
		}
		void Apple() override { cout << "CB::Apple Shimla\n"; }
		~CB()
		{//setvptr(CB::Vftable)
		}//CA::~CA()
	};

	int main()
	{
		CB obj1;//CB::CB()
		obj1.DoJob();
		obj1.CA::~CA();
		line();
		obj1.DoJob();

		return 0;
	}
