#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"
namespace nm25
{
	class CArray;//forward declarartion

	class Element
	{
		CArray* pt;
		int index;
	public:
		Element(CArray* pt, int index) :pt(pt), index(index)
		{
		}
		operator int();
		Element& operator=(int val);
		Element& operator=(Element par);
	};

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

		Element operator[](int index)
		{
			return Element(this, index);
		}
		friend ostream& operator<<(ostream&, const CArray&);
		~CArray()
		{
			delete[] arr;
		}
		friend class Element;
	};
	ostream& operator<<(ostream& os, const CArray& par)
	{
		for (int i = 0; i < par.size; i++)
		{
			os << "arr[ " << i << " ] = " << par.arr[i] << '\n';
		}
		return os;
	}

	Element::operator int()
	{
		cout << "reading\n";
		return pt->arr[index];
	}
	Element& Element::operator = (int val)
	{
		cout << "writing\n";
		pt->arr[index] = val;
		return *this;
	}
	Element& Element::operator=(Element par)
	{
		cout << "reading/writing\n";
		pt->arr[index] = par.pt->arr[par.index];
		return *this;
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
}