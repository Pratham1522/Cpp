#include<iostream>
using std::cout;
#define line(m) cout<<"___________________________\n"

namespace nm48
{
	class CC
	{
		static int count;
		int x{ 0 };
	public:
		CC() :x(++count)
		{
			cout << "CC ctor\n";
		}
		CC(CC&&) noexcept// = default;//:x(++count)
		{
			cout << "CC Move\n";
		}
		CC(const CC&) :x(++count)
		{
			cout << "CC Copy\n";
		}
		CC& operator=(const CC&)
		{
			cout << "CC Assignmnet\n";
			return *this;
		}
		CC& operator=(CC&&)
		{
			cout << "CC Move Assignmnet\n";
			return *this;
		}
		~CC() noexcept
		{
			cout << "CC D-tor x : " << x << '\n';
		}
	};
	int CC::count = 0;

	int main1()
	{
		int par = 10;

		try
		{
			CC obj;

			if (10 == par)
			{
				throw obj;
			}

		}
		catch (CC exp)
		{
			cout << "CC Exp : " << '\n';
		}

		return 0;
	}


	int main2()
	{

		CC obj;
		CC obj1 = obj;
		CC obj2;
		line();
		obj = obj2;
		line();
		obj = std::move(obj2);
		line();
		return 0;
	}


	class CA
	{
	public:
		CA() = default;

		CA(CA&&) noexcept = default;

		CA(const CA&) = delete;

		CA& operator=(const CA&) = delete;

		CA& operator=(CA&&) = default;

		~CA() noexcept = default;

		void Display() const
		{
		}
		void setState()
		{
		}
	private:
		/*int _id;
		int did_;
		int m_projId;
		int m_comp_id;*/
	};


	int main()
	{
		CA obj1;
		const CA obj2;

		obj1.Display();
		obj1.setState();

		obj2.Display();//const objects can access inpectors only(const functions)


		return 0;
	}
}