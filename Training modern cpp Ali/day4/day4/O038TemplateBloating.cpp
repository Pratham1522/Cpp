
namespace nm37
{
	//rejected (template Bloating)
	template<typename T>
	class Stack
	{
		T arr[5];
		int top = -1;
	public:
		void Push(T val)
		{
			arr[++top] = val;
		}
		T Pop()
		{
			return arr[top--];
		}
		T Peek()
		{
			return arr[top];
		}
		bool IsEmpty()
		{
			return top == -1;
		}
		bool IsFull()
		{
			return top == 4;
		}
	};

	int main()
	{
		Stack<int> st1;
		st1.Push(10);
		st1.Pop();
		st1.Peek();
		st1.IsEmpty();
		st1.IsFull();

		Stack<double> st2;
		st2.Push(3.01);
		st2.Pop();
		st2.Peek();
		st2.IsEmpty();
		st2.IsFull();

		Stack<float> st3;
		st3.Push(3.01f);
		st3.Pop();
		st3.Peek();
		st3.IsEmpty();
		st3.IsFull();
		return 0;
	}
}