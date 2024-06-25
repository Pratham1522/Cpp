## Template method pattern
```cpp
class Account
	{
	protected:
		virtual void ActualDebit(int Accid, int amount) = 0;

	public:
		void Debit(int Accid, int amount)
		{
			cout << "Open DB\n";
			ActualDebit(Accid, amount);
			cout << "Close DB\n";
		}
	};

	class SavingsAccount :public Account
	{
	protected:
		void ActualDebit(int Accid, int amount) override
		{
			cout << "Debit Savings\n";
		}
	};

	class CurrentAccount :public Account
	{
	protected:
		void ActualDebit(int Accid, int amount) override
		{
			cout << "Debit Current\n";
		}
	};

	int main()
	{
		SavingsAccount sa;
		sa.Debit(101, 100);
		line();
		CurrentAccount cu;
		cu.Debit(102, 200);
		return 0;
	}
```
- Eg 2 :
```cpp
class CBubbleSort
    {
        friend ostream& operator<<(ostream& os, CBubbleSort& par)
        {
            for (size_t i = 0; i < 5; i++)
            {
                os << par.arr[i] << '\t';
            }os << '\n';
            return os;
        }
        int arr[5];
    protected:
        virtual bool CompareValues(int&, int&) = 0;
    public:
        CBubbleSort() :arr{ 10,40,20,30,50 }
        {
        }
        void Sort()
        {
            int n = 5;
            int i, j;
            bool swapped;
            for (i = 0; i < n - 1; i++) {
                swapped = false;
                for (j = 0; j < n - i - 1; j++) {
                    if (CompareValues(arr[j], arr[j + 1])) {
                        std::swap(arr[j], arr[j + 1]);
                        swapped = true;
                    }
                }
                if (swapped == false)
                    break;
            }
        }
    };

    //problem
    class CBubbleSortAsc :public  CBubbleSort
    {
    protected:
        bool CompareValues(int& p1, int& p2) override
        {
            return p1 > p2;
        }
    };

    class CBubbleSortDesc :public CBubbleSort
    {
    protected:
        bool CompareValues(int& p1, int& p2) override
        {
            return p1 <= p2;
        }
    };

    int main()
    {
        CBubbleSortAsc asc;
        CBubbleSortDesc desc;
        asc.Sort();
        desc.Sort();
        cout << asc << desc << '\n';
        return 0;
    }
```
