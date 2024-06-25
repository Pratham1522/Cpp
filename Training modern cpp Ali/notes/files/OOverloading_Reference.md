
## Reference opertor overloading
```addressof(var)``` : return memory address.  
```cpp
	class CA
	{
		int x;
		int y;
	public:
		CA(int p1, int p2) :x(p1), y(p2) //param const
		{
            cout<<"CA param constructor \n";
		}
		void* operator&()     //refernce operator overloading
		{
			return &y;
		}
	};
	int main()
	{
		CA obj(10, 20);
		line();
		cout << "&obj : [ " << &obj << " ]\n";
		cout << "addressof(obj) : [ " << addressof(obj) << " ]\n";

		return 0;
	}
```
