
## Explicit keyword 
- When a constructor or conversion function is declared as explicit, it means that the compiler will not automatically apply it for implicit conversions. 
```cpp
class CA
	{
		int x;
		int y;
	public:
		explicit CA(int x) :x(x), y(x)
		{
			cout << "one param ctor\n";
		}
		explicit CA(int x, int y) :x(x), y(x)
		{
			cout << "two param ctor\n";
		}
		void Disp()
		{
			cout << "x=" << x << " y="<<y<< '\n';
		}
		CA& operator=(const CA& par)
		{
			cout << "Assignment\n";
			this->x = par.x;
			return *this;
		}
        CA& operator=(int value) 
        {
            cout << "Assignment from int\n";
            this->x = value;
            return *this;
        }
	};

	void f1(CA par)
	{
		cout << "Apple\n";
	}

	
	int main()
	{
		CA obj1(100);
		obj1.Disp();  

		// CA obj2 = 200; //error as one para constructor is explicit.
        CA obj2 = CA(200);  //this works
		obj2.Disp();

		obj1 = 300;//conversion and then assignment,need '=' operator overload with int.
		obj1.Disp();

		// f1(10);//error on explicit ctor
		f1(CA(100)); // this works
		return 0;
	}
```
