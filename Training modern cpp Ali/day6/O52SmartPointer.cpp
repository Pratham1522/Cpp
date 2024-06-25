#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"

namespace nm52
{
	class CA
	{
	public:
		CA()
		{
			//cout << "Default \n";
		}
		CA(const CA& par)
		{
			//cout << "Copy\n";
		}
		CA(CA&& par) noexcept
		{
			//cout << "Move\n";
		}
		~CA() noexcept
		{
			//cout << "D-tor\n";
		}
	};

	class CB
	{
	public:
		CB()
		{
			cout << "CB Ctor\n";
		}
		CB(int)
		{
			cout << "CB(int)\n";
		}
		CB(int, int)
		{
			cout << "CB(int,int)\n";
		}
		void fun()
		{
			cout << "CB::fun\n";
		}
		CB(CA par)
		{
			cout << "CB(CA)\n";
		}
		~CB()
		{
			cout << "CB D-tor\n";
		}
	};


	template<typename T>
	struct Handle
	{
		T* pt;
		Handle(T* pt) :pt(pt), count(1)
		{
		}
		int count;
		~Handle()
		{
			delete pt;
		}
	};

	template<typename T>
	class Smart
	{
		Handle<T>* hndl{ nullptr };
	public:
		explicit Smart(T* pt = nullptr)
		{
			if (pt != nullptr)
			{
				hndl = new Handle<T>(pt);
			}
		}
		Smart(Smart&& par) noexcept :hndl(par.hndl)
		{
			par.hndl = nullptr;
		}
		Smart(const Smart& par) :hndl(par.hndl)
		{
			if (hndl != nullptr)
			{
				hndl->count++;
			}
		}
		Smart& operator=(const Smart& par)
		{
			Smart temp(par);//copy and swap
			this->Swap(temp);
			return *this;
		}

		void Swap(Smart& tmp)
		{
			std::swap(this->hndl, tmp.hndl);
		}

		int use_count() const
		{
			return (hndl == nullptr) ? 0 : hndl->count;
		}
		T& operator*() const
		{
			return *(hndl->pt);
		}
		T* operator->() const
		{
			return hndl->pt;
		}
		operator bool()
		{
			return hndl != nullptr;
		}
		~Smart() noexcept
		{
			if (hndl != nullptr && --(hndl->count) == 0)
			{
				delete hndl;
			}
		}
	};

	template<typename T, typename... PCK>
	Smart<T> make_smart(PCK&&... pck)
	{
		return Smart<T>(new T(std::forward<PCK>(pck)...));
	}

	void My_Smart()
	{
		Smart<CB> smt1;//0
		Smart<CB> smt2;//3
		Smart<CB> smt3(new CB());//3
		line();
		Smart<CB> smt4 = make_smart<CB>();//1
		line();
		Smart<CB> smt5 = make_smart<CB>();//2
		line();
		Smart<CB> smt6 = smt5;//2
		Smart<CB> smt7 = smt3;//3
		smt2 = smt7;
		cout << smt1.use_count() << '\n';
		cout << smt2.use_count() << '\n';
		cout << smt3.use_count() << '\n';
		cout << smt4.use_count() << '\n';
		cout << smt5.use_count() << '\n';
		cout << smt6.use_count() << '\n';
		cout << smt7.use_count() << '\n';
		line();
		//if (smt1.use_count() > 0)
		if (smt1)
		{
			smt1->fun();
			(*smt1).fun();
		}
		line();
	}



	void My_Smart_1()
	{
		shared_ptr<CB> smt1;//0
		shared_ptr<CB> smt2;//3
		shared_ptr<CB> smt3(new CB());//3
		line();
		shared_ptr<CB> smt4 = make_shared<CB>();//1
		line();
		shared_ptr<CB> smt5 = make_shared<CB>();//2
		line();
		shared_ptr<CB> smt6 = smt5;//2
		shared_ptr<CB> smt7 = smt3;//3
		smt2 = smt7;
		cout << smt1.use_count() << '\n';
		cout << smt2.use_count() << '\n';
		cout << smt3.use_count() << '\n';
		cout << smt4.use_count() << '\n';
		cout << smt5.use_count() << '\n';
		cout << smt6.use_count() << '\n';
		cout << smt7.use_count() << '\n';
		line();
		//if (smt1.use_count() > 0)
		if (smt1)
		{
			smt1->fun();
			(*smt1).fun();
		}
		line();
	}

	int main()
	{
		My_Smart();
		cout << "*******************************************\n";
		My_Smart_1();
		return 0;
	}
}
