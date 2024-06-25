#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"

//when you write to array it should print write, when u read print read, when both read/write then print same

	//Rohan
	class Element
	{
		int* pt;
		int index;
	public:
		Element(int* pt, int index) :pt(pt), index(index) //get array address and index
		{
		}
		operator int()
		{
			cout << "reading\n";
			return pt[index]; //return value store at arr[index]
		}
		Element& operator=(int val)   
		{
			cout << "writing\n";
			pt[index] = val;
			return *this;
		}
		Element& operator=(Element par)
		{
			cout << "reading/writing\n";
			pt[index] = par.pt[par.index];
			return *this;
		}
	};

	class CArray
	{
		int size;   //create a heap array of given size.
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
		//problem here we cant get the index value in '=' overloading ,so we implement another class element
		Element operator[](int index)
		{
			return Element(arr, index);
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
