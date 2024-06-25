#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"

namespace nm33
{
	class CA
	{
	public:
		CA()
		{
			cout << "CA Ctor\n";
		}
		void fun()
		{
			cout << "CA fun\n";
		}
		~CA()
		{
			cout << "CA D-tor\n";
		}
	};

	void DoBusiness(CA* caPtr)
	{
		cout << "Business Started\n";
		caPtr->fun();
		cout << "Business Done\n";
	}

	//-----------------------------------------------------
	class Smart_Ptr
	{
		static void* operator new(size_t) = delete;
		static void* operator new[](size_t) = delete;
		static void operator delete(void*) = delete;
		static void operator delete[](void*) = delete;
		CA* pt;
	public:
		Smart_Ptr(CA* pt = NULL) :pt(pt)
		{
		}
		//ownership transfer.
		Smart_Ptr(const Smart_Ptr& par) :pt(par.pt)
		{
			Smart_Ptr& parRef = const_cast<Smart_Ptr&>(par);
			parRef.pt = NULL;
		}

		Smart_Ptr& operator=(const Smart_Ptr& par)
		{
			Smart_Ptr temp(par);
			temp.Swap(*this);//this->Swap(temp);
			return *this;
		}

		void Swap(Smart_Ptr& tmp)
		{
			std::swap(this->pt, tmp.pt);
		}

		CA* operator->()
		{
			return pt;
		}

		CA& operator*()
		{
			cout << "operator*\n";
			return *pt;
		}
		operator CA* ()
		{
			cout << "CA*\n";
			return pt;
		}

		~Smart_Ptr()
		{
			delete pt;
		}
	};

	void MyBusiness(Smart_Ptr smpt)
	{
		cout << "Apple\n";
		smpt->fun();
		cout << "Ornge\n";
	}


	void MyBusinessNew(Smart_Ptr& smpt)
	{
		cout << "Apple1\n";
		(*smpt).fun();
		cout << "Ornge1\n";
	}

	int main()
	{
		Smart_Ptr sm1 = new CA();
		Smart_Ptr sm1_1 = new CA();
		//sm1->fun();
		//(*sm1).fun();
		line(CA*);
		DoBusiness(sm1);
		line();
		MyBusiness(sm1);//Smart_Ptr smpt=sm1;
		line();
		Smart_Ptr sm2;
		sm2 = sm1_1;
		line(operator*);
		MyBusinessNew(sm2);
		line();
		return 0;
	}
}
