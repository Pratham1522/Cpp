
## Nested Class
```cpp
class CArray
	{
		int size;
		int* arr;
	public:
		CArray(int par) :size(par), arr(new int[size])
		{
			arr[0] = 10;
			arr[1] = 20;
			arr[2] = 30;
			arr[3] = 40;
			arr[4] = 50;
		}

		//nested classses are automatically friend of outer class.
		class Element  //nested class
		{
			CArray* pt;
			int index;
		public:
			Element(CArray* pt, int index) :pt(pt), index(index)
			{
			}
			operator int()//used when CA to int conversion.
			{
				cout << "reading\n";
				return pt->arr[index];
			}
			Element& operator = (int val)
			{
				cout << "writing\n";
				pt->arr[index] = val;
				return *this;
			}
			Element& operator=(Element par)
			{
				cout << "reading/writing\n";
				pt->arr[index] = par.pt->arr[par.index];
				return *this;
			}
		};

		Element operator[](int index)
		{
			return Element(this, index);
		}
		friend ostream& operator<<(ostream&, const CArray&);
		~CArray()
		{
			delete[] arr;
		}
	};
	ostream& operator<<(ostream& os, const CArray& par)
	{
		for (int i = 0; i < par.size; i++)
		{
			os << "arr[ " << i << " ] = " << par.arr[i] << '\n';
		}
		return os;
	}

	int main()
	{
		CArray obArr(5);
		int k = obArr[1];//read
		obArr[0] = 999;//write
		obArr[1] = obArr[0];//read/write
		cout << obArr << "k=" << k << '\n';
		return 0;
	}
```
