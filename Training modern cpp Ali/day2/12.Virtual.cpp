// once a obj is destructed it forgot the virtual behaviour

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
		CB()//first CA::CA() ,then setvptr(CB::Vftable)
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
		obj1.DoJob();     //CA::Dojob():CB::Apple
		obj1.CA::~CA();  // it deletes the vptr created
		line();
		obj1.DoJob();  // CA::Dojob():CA::Apple()
				
		return 0;
	}
