//3rd asa type cha hota,exact kunal la mahit asel,mi bgitla ch nhi.
#include<iostream>
using namespace std;

template<typename T>
class Smart
{
public:
	static void* operator new(size_t) = delete;
	static void* operator new[](size_t) = delete;
	static void operator delete(void*) = delete;
	static void operator delete[](void*) = delete;
	using FPTR = void(T::*)();
	Smart(T* pt = nullptr) :pt(pt)
	{
	}
	Smart(const Smart& par):pt(par.pt)
	{
		Smart& smartRef = const_cast<Smart&>(par);
		smartRef.pt = nullptr;
	}
	Smart& operator=(Smart&&) = delete;
	Smart(Smart&& par) noexcept :pt(par.pt)
	{
		par.pt = nullptr;
	}
	Smart& operator=(const Smart& par)
	{
		Smart temp(par);
		this->Swap(temp);
		return *this;
	}
	operator bool()
	{
		return pt != nullptr;
	}
	T* operator->()
	{
		return pt;
	}
	T& operator*()
	{
		return *pt;
	}
	Smart& operator->*(FPTR fp)
	{
		this->fp = fp;
		return *this;
	}
	void operator()()
	{
		(pt->*fp)();
	}
	void Swap(Smart& tmp)
	{
	  std::swap(this->pt , tmp.pt);
	}
	~Smart() noexcept
	{
	   delete pt;
	}
private:
	T* pt{nullptr};
	FPTR fp{nullptr};
};

template<typename T,typename... PCK>
Smart<T> make_smart(PCK&&... pck)
{
	return Smart<T>(new T(std::forward<PCK>(pck)...));
}

template<typename T>
void TestMemberCallback(Smart<T>& sm, typename Smart<T>::FPTR fp)
{
	cout << "Business started\n";
	(sm->*fp)();
	cout << "Business completed\n";
}

class CA
{
public:
	CA()
	{
		cout << "CA::Ctor\n";
	}
	CA(int)
	{
		cout << "CA::Ctor(int)\n";
	}
	CA(double,double)
	{
		cout << "CA::Ctor(double,double)\n";
	}
	void fa1()
	{
		cout << "CA::fa1\n";
	}
	void fa2()
	{
		cout << "CA::fa2\n";
	}
	~CA()
	{
		cout << "CA::Dtor\n";
	}
};


class CB
{
public:
	CB()
	{
		cout << "CB::Ctor\n";
	}
	CB(double)
	{
		cout << "CB::Ctor(double)\n";
	}
	CB(string, string)
	{
		cout << "CB::Ctor(string,string)\n";
	}
	void fb1()
	{
		cout << "CB::fb1\n";
	}
	void fb2()
	{
		cout << "CB::fb2\n";
	}
	~CB()
	{
		cout << "CB::Dtor\n";
	}
};

void TestCA()
{
	Smart<CA> sm1(new CA());
	sm1->fa1();
	Smart<CA> sm2 = make_smart<CA>(1.0, 2.0);
	sm1 = sm2;
	if (sm1)
	{
		sm1->fa1();
		(*sm1).fa2();
	}
	TestMemberCallback(sm1, &CA::fa1);
	TestMemberCallback(sm1, &CA::fa2);
}


void TestCB()
{
	Smart<CB> sm1(new CB());
	sm1->fb1();
	Smart<CB> sm2 = make_smart<CB>("sachin", "saurav");
	sm1 = sm2;
	if (sm1)
	{
		sm1->fb1();
		(*sm1).fb2();
	}
	TestMemberCallback(sm1, &CB::fb1);
	TestMemberCallback(sm1, &CB::fb2);
}

int main()
{
	TestCA();
	cout << "********************************\n";
	TestCB();
	return 0;
}