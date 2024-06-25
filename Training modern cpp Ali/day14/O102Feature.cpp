#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"

namespace nm102
{

	class CArray
	{
		int row = 2;
		int col = 3;
		int arr[2][3]{ {10,20,30},{40,50,60} };
	public:
		CArray(int par)
		{
		}
		class Helper
		{
			CArray* pt;
			int index1;
		public:
			Helper(CArray* pt, int index) :pt(pt), index1(index)
			{
			}

			class InnerHelper
			{
				CArray* pt;
				int index1;
				int index2;
			public:
				InnerHelper(CArray* pt, int index1, int index2) :pt(pt), index1(index1), index2(index2)
				{
				}
				operator int()
				{
					cout << "reading\n";
					return pt->arr[index1][index2];
				}
				InnerHelper& operator = (int val)
				{
					cout << "writing\n";
					pt->arr[index1][index2] = val;
					return *this;
				}
				InnerHelper& operator=(InnerHelper par)
				{
					cout << "reading/writing\n";
					pt->arr[index1][index2] = par.pt->arr[par.index1][par.index2];
					return *this;
				}
			};

			InnerHelper operator[](int index)
			{
				return InnerHelper(pt, index1, index);
			}
		};


		Helper operator[](int index)
		{
			return Helper(this, index);
		}

		friend ostream& operator<<(ostream&, const CArray&);
		~CArray()
		{
		}
	};
	ostream& operator<<(ostream& os, const CArray& par)
	{
		for (int i = 0; i < par.row; i++)
		{
			for (int j = 0; j < par.col; j++)
			{
				os << par.arr[i][j] << '\n';
			}
		}
		return os;
	}

	int main()
	{
		CArray obArr(5);
		int k = obArr[0][1];//read
		obArr[0][1] = 999;//write
		obArr[1][1] = obArr[0][1];//read/write
		cout << obArr << "k=" << k << '\n';
		return 0;
	}
}