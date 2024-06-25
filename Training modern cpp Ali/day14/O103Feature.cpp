#include<iostream>
#include<variant>
#include<map>
#include<functional>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"

namespace nm103
{
	int main1()
	{
		auto x = 10;
		decltype(x * 1.1) y = 100;
		tuple<int, double> tup(100, 3.14159);
		variant<int, double, float, char> v = 100;
		try
		{
			cout << "current index in v : " << v.index() << '\n';
			int res = std::get<0>(v);
			cout << "res : " << res << '\n';

			v = 3.14159;
			cout << "current index in v : " << v.index() << '\n';
			double res1 = std::get<1>(v);
			cout << "res1 : " << res << '\n';

			v = 1.2f;
			cout << "current index in v : " << v.index() << '\n';
			float res2 = std::get<float>(v);
			cout << "res2 : " << res2 << '\n';


			v = 's';
			double d = std::get<double>(v);
			cout << "current index in v : " << v.index() << '\n';
		}
		catch (bad_variant_access& exp)
		{
			cout << exp.what() << '\n';
		}
		return 0;
	}

	class CAT
	{
	public:
		CAT()
		{
			cout << "CAT()\n";
		}
		void catFun()
		{
			cout << "CAT::catFun\n";
		}
		~CAT()
		{
			cout << "~CAT()\n";
		}
	};


	class DOG
	{
	public:
		DOG()
		{
			cout << "DOG()\n";
		}
		void dogFun()
		{
			cout << "DOG::dogFun\n";
		}
		~DOG()
		{
			cout << "~DOG()\n";
		}
	};


	class OX
	{
	public:
		OX()
		{
			cout << "OX()\n";
		}
		void oxFun()
		{
			cout << "OX::oxFun\n";
		}
		~OX()
		{
			cout << "~OX()\n";
		}
	};


	void DoJob1(variant<OX, CAT, DOG> animal)
	{
		int index = animal.index();
		switch (index)
		{
		case 0: {
			OX ox = std::get<0>(animal);
			ox.oxFun();
			break;
		}

		case 1:
		{
			CAT cat = std::get<1>(animal);
			cat.catFun();
			break;
		}
		case 2:
		{
			DOG dog = std::get<2>(animal);
			dog.dogFun();
			break;
		}
		};
		line();
	}

	class Shaunak1
	{
		map<int, std::function<void(variant<OX, CAT, DOG>&)>> repo;
	public:
		Shaunak1()
		{
			repo[0] = [](variant<OX, CAT, DOG>& anm) {
				OX ox = std::get<0>(anm);
				ox.oxFun();
			};

			repo[1] = [](variant<OX, CAT, DOG>& anm) {
				CAT cat = std::get<1>(anm);
				cat.catFun();
			};

			repo[2] = [](variant<OX, CAT, DOG>& anm) {
				DOG dog = std::get<2>(anm);
				dog.dogFun();
			};
		}
		void get_func(variant<OX, CAT, DOG>& animal)
		{
			repo[animal.index()](animal);
		}
	}shaunak1;


	class Shaunak
	{
		map<int, void(*)(variant<OX, CAT, DOG>&)> repo;
	public:
		Shaunak()
		{
			repo[0] = [](variant<OX, CAT, DOG>& anm) {
				OX ox = std::get<0>(anm);
				ox.oxFun();
			};

			repo[1] = [](variant<OX, CAT, DOG>& anm) {
				CAT cat = std::get<1>(anm);
				cat.catFun();
			};

			repo[2] = [](variant<OX, CAT, DOG>& anm) {
				DOG dog = std::get<2>(anm);
				dog.dogFun();
			};
		}
		void get_func(variant<OX, CAT, DOG>& animal)
		{
			repo[animal.index()](animal);
		}
	}shaunak;


	void DoJob2(variant<OX, CAT, DOG> animal)
	{
		shaunak.get_func(animal);
		line();
	}


	class Func
	{
	public:
		void operator()(OX& ox)
		{
			ox.oxFun();
		}
		void operator()(DOG& dog)
		{
			dog.dogFun();
		}
		void operator()(CAT& cat)
		{
			cat.catFun();
		}
	};

	void DoJob(variant<OX, CAT, DOG> animal)
	{
		std::visit(Func{}, animal);
		line();
	}

	int main()
	{
		DOG dog;
		CAT cat;
		OX ox;

		line();
		DoJob(dog);
		DoJob(cat);
		DoJob(ox);
		line();

		return 0;
	}
}