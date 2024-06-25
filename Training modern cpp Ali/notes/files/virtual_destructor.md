
## Virtual Destructor 
- Virtual destructors provide the necessary mechanism for proper cleanup in polymorphic hierarchies, ensuring that resources are released correctly regardless of the type of object being deleted.
- When a base class pointer pointing to a derived class object is deleted, having a virtual destructor ensures that the appropriate destructor is called in the correct order.
- if ~CA is not 'virtual' then `delete pt;` will call `CA::~CA` and `CA::delete` as pointer has a base type , but appropriately `CB::~CB` ,`CA::~CA` and `CB::delete` should get called. 
```cpp
class CA
{
public:
	static void* operator new(size_t size)
	{
		cout << "CA::operator new\n";
		return malloc(size);
	}
	static void operator delete(void *pv)
	{
		cout << "CA::operator delete\n";
		free(pv);
	}
	CA()
	{
		cout << "CA Ctor\n";
	}
	virtual ~CA() 
	{
		cout << "CA D-tor\n";
	}
};

class CB:public CA
{
public:
	CB()
	{
		cout << "CB Ctor\n";
	}
	static void* operator new(size_t size)
	{
		cout << "CB::operator new\n";
		return malloc(size);
	}
	static void operator delete(void* pv)
	{
		cout << "CB::operator delete\n";
		free(pv);
	}
	~CB()
	{
		cout << "CB D-tor\n";
	}
};

int main()
{
	CA* pt = new CB();
	delete pt;

	return 0;
}
```
