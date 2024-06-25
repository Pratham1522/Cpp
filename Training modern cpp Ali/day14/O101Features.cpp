#include<iostream>
#include<string>
#include<vector>
using namespace std;


	//fold expressions
	template<typename... PCK>
	auto sum1(PCK... pck)
	{
		return (pck + ...);
	}

	template<typename... PCK>
	void ShowAll(PCK... pck)
	{
		//(cout << ... << pck) << '\n';
		((cout << pck << '\t'), ...) << '\n';
	}

	class CComplex
	{
		double _real{ 0.0 };
		double _imag{ 0.0 };
	public:
		CComplex(double real, double imag) :_real(real), _imag(imag)
		{
		}
		CComplex operator+(const CComplex& par) const
		{
			return CComplex(this->_real + par._real, this->_imag + par._imag);
		}
		CComplex operator+(double par) const
		{
			return CComplex(this->_real, this->_imag + par);
		}
		friend CComplex operator+(double val, const CComplex& par)
		{
			return CComplex(par._real + val, par._imag);
		}
		friend ostream& operator<<(ostream& os, const CComplex& com)
		{
			os << com._real << (com._imag >= 0.0 ? "+" : "") << com._imag << '\n';
			return os;
		}
		explicit operator double()
		{
			return 3.141;
		}
		operator tuple<double, double>()
		{
			return { _real,_imag };
		}

	};

	template<typename T, typename... PCK>
	void pushAll(vector<T>& vec, PCK&&... pck)
	{
		(vec.push_back(std::forward<PCK>(pck)), ...);
	}

	template<typename T>
	ostream& operator<<(ostream& os, vector<T>& vec)
	{
		for (size_t i = 0; i < vec.size(); i++)
		{
			os << vec[i] << '\t';
		}
		os << '\n';
		return os;
	}


	int main()
	{
		//use fold expressions
		auto res = sum1(10, 20, 30, 40, 50, 60, 70);
		cout << res << '\n';

		auto res1 = sum1(10, 20, 30);
		cout << res1 << '\n';


		ShowAll(1.2, "sachin", 3.14f, 'c', 1, 2, 3);//ensure tab spaces between every display
		ShowAll(1, 2, 3);//ensure tab spaces between every display

		CComplex c1(10, 20);
		CComplex c2(20, 40);

		CComplex c3 = c1 + c2;

		CComplex c4 = c1 + 10;//10 to added to imaginary part
		CComplex c5 = 10 + c1;//10 to added to real part

		double d = (double)c5; // recieves (real + imag)

		tuple<double, double> t = c5; //recieves real and imag

		cout << c1 << c2 << c3 << c4 << c5;
		cout << d << '\t' << std::get<0>(t) << '\t' << std::get<1>(t) << '\n';

		vector v1{ 10 };
		pushAll(v1, 20, 30, 40, 50, 60, 70, 80);
		cout << v1 << '\n';

		return 0;
	}

