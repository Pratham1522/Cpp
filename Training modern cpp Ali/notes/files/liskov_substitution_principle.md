## LSP -> Liskov's Substitution Principle
- base class pointer , derived class object.
```cpp
class IX //Interface
	{
	public:
		virtual void fx1() = 0;
		virtual void fx2() = 0;
	};

	class CX :public IX
	{
	public:
		void fx1() override
		{
			cout << "CX::fx1\n";
		}

		void fx2() override
		{
			cout << "CX::fx2\n";
		}
	};

	int main()
	{
		CX obj;
		obj.fx1();
		obj.fx2();
		line();
		IX* px = &obj;//LSP
		px->fx1();//px->vptr->vtable[0]();
		px->fx2();//px->vptr->vtable[1]();
		line();
		IX& pxRef = obj;
		pxRef.fx1();//pxRef.vptr->vtable[0]();
		pxRef.fx2();//pxRef.vptr->vtable[0]();
		return 0;
	}
```
- Eg 2 : **object slicing** : object only know his partition, not other object area.
```cpp
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


	int main()
	{
		//CX obj;
		IX* px = new CX();//LSP
		px->fx1();//px->vptr->vtable[0]();  CX::fx1
		px->fx2();//px->vptr->vtable[1]();  CX::fx2
		line();
		cout << "px : [ " << px << " ]\n";

		// IY* py = (IY*)px;         method 1
		// py++; //pyvtr = pxvptr + 1

        // IY* py = (IY*)(CX*)px;    method 2

        IY* py = dynamic_cast<IY*>(px); //mthod 3

		cout << "py : [ " << py << " ]\n";
		line();
		py->fy1();//py->vptr->vtable[0]();  CX::fy1
		py->fy2();//py->vptr->vtable[1]();  CX::fy2
		return 0;
	}
```
