#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"

namespace nm19
{
	//interface
	class IX
	{
	public:
		virtual void fx1() = 0;
		virtual void fx2() = 0;
	};

	class IY
	{
	public:
		virtual void fy1() = 0;
		virtual void fy2() = 0;
	};

	class CX :public IX, public IY
	{
	public:
		void fx1() override
		{
			cout << "fx1\n";
		}

		void fx2() override
		{
			cout << "fx2\n";
		}
		void fy1() override
		{
			cout << "fy1\n";
		}

		void fy2() override
		{
			cout << "fy2\n";
		}
	};


	//unexpected result (px and py pointing to same vptr)
	int main1()
	{
		//CX obj;
		IX* px = new CX();//LSP
		px->fx1();//px->vptr->vtable[0]();  CX::fx1
		px->fx2();//px->vptr->vtable[1]();  CX::fx2
		line();
		cout << "px : [ " << px << " ]\n";
		IY* py = (IY*)px;
		cout << "py : [ " << py << " ]\n";
		line();
		py->fy1();//py->vptr->vtable[0]();  CX::fx1
		py->fy2();//py->vptr->vtable[1]();  CX::fx2
		return 0;
	}


	int main2()
	{
		//CX obj;
		IX* px = new CX();//LSP
		px->fx1();//px->vptr->vtable[0]();  CX::fx1
		px->fx2();//px->vptr->vtable[1]();  CX::fx2
		line();
		cout << "px : [ " << px << " ]\n";
		IY* py = (IY*)px;
		py++; //pyvtr = pxvptr + 1
		cout << "py : [ " << py << " ]\n";
		line();
		py->fy1();//py->vptr->vtable[0]();  CX::fy1
		py->fy2();//py->vptr->vtable[1]();  CX::fy2
		return 0;
	}

	int main3()
	{
		//CX obj;
		IX* px = new CX();//LSP
		px->fx1();//px->vptr->vtable[0]();  CX::fx1
		px->fx2();//px->vptr->vtable[1]();  CX::fx2
		line();
		cout << "px : [ " << px << " ]\n";
		IY* py = (IY*)(CX*)px;
		cout << "py : [ " << py << " ]\n";
		line();
		py->fy1();//py->vptr->vtable[0]();  CX::fy1
		py->fy2();//py->vptr->vtable[1]();  CX::fy2
		return 0;
	}

	int main()
	{
		//CX obj;
		IX* px = new CX();//LSP
		px->fx1();//px->vptr->vtable[0]();  CX::fx1
		px->fx2();//px->vptr->vtable[1]();  CX::fx2
		line();
		cout << "px : [ " << px << " ]\n";
		IY* py = dynamic_cast<IY*>(px);
		cout << "py : [ " << py << " ]\n";
		line();
		py->fy1();//py->vptr->vtable[0]();  CX::fy1
		py->fy2();//py->vptr->vtable[1]();  CX::fy2
		return 0;
	}

}
