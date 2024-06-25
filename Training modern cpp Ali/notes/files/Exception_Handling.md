## exception handling .
- very costly , perform is necessary and no other option.
- if excetion is thrown and you don't catch it, your program will terminate.
- std::set_terminate(fun1) : set custom function which will be called in place of termination instead of system termination.
```cpp
    void fun(int par)
	{
		if (10 == par)
		{
			throw 100;
		}
	}
    void Kpit_Terminate()
	{
		cout << "Kpit_Terminate\n";
		exit(0);
	}
	int main3()
	{
		std::set_terminate (Kpit_Terminate);
		fun(10);
		return 0;
	}
```
- there can be multiple catch block for a try block
- compiler creates a catch table for every try catch.

 **if thrown a obj** 
- a default const called at object creation
- a copy const will be called at throw
- destuctor called for created obj at epilog of try block
- a copy const called for creating a obj in catch table
- a copy const called at catch block prolog
- and two destructor at elilog of catch block.
```cpp
	int main()
	{
		int par = 10;
		try
		{
			CA obj;//CA::CA
			if (10 == par)
			{
				throw obj;//CA::CA(copy)
			}
		}//CA::~CA
		//catch table : CA::CA(copy)
		catch (CA exp)//CA::CA(copy)
		{
			cout << "CA Exp : " << '\n';
		}//CA::~CA(catch block) 
        // CA::~CA(catch table)
		cout << "Done\n";
		return 0;
	}
```
- if a class inherit from a class and inheriting class object pointer is thrown then in catch also inheriting class object will be catched, not base class.

**for nested try**
- we can modify the exp to be thown inside inner try ,
- throw keyword is used , then previous exp is returned , modified is returned if reference is used.
```cpp
int main()
{
	int par = 10;
	try
	{
		try
		{
			CA obj; //CA
			if (10 == par)
			{
				throw 100;
    		}//~CA
        }
		catch (int& exp)
        {
			exp += 100;  //can do ,exp=200
			cout << "inner int Exp : "<<exp << '\n';
			// throw exp;//replace , throw changed exp 
			// throw 200;//replace , throw 200.
			throw;  //rethrow ,will throw 200
		}
		catch (int exp)
		{
			// exp += 100;  //can do ,exp=200
			cout << "inner int Exp : "<<exp << '\n';
			// throw exp;//replace ,throw changed exp
			// throw 200;//replace , throw 200.
			throw;//rethrow ,will throw 100
		}
	}
	catch (int exp)
	{
			cout << "outer int Exp : "<<exp << '\n';
	}
	return 0;
}
```
