#include<iostream>
#include<string>
#include<map>
using namespace std;
#define line(msg) cout<<"___________________"msg"____________________\n"

namespace nm56
{
	struct MSP
	{
		string m_make;
		string m_series;
		string m_processor;
		MSP(string make,
			string series,
			string processor) :m_make(make),
			m_series(series),
			m_processor(processor)
		{
			count++;
		}
		static int count;
		static map<string, MSP*> repo;
		static MSP* make_msp(string make, string series, string processor)
		{
			string key = make + series + processor;
			if (repo.find(key) == repo.end())
			{
				repo[key] = new MSP(make, series, processor);
			}
			return repo[key];
		}
		static void release()
		{
			for (auto& rng : repo)
			{
				delete rng.second;
			}
			repo.clear();
		}
	};
	int MSP::count = 0;
	map<string, MSP*> MSP::repo;

	class Computer
	{

		string m_ram;
		string m_hd;
		string m_mon;
		MSP* msp;
	public:
		Computer(string make,
			string series,
			string processor,
			string ram,
			string hd,
			string mon) :
			m_ram(ram),
			m_hd(hd),
			m_mon(mon), msp(MSP::make_msp(make, series, processor))
		{
			count++;
		}
		friend ostream& operator<<(ostream& os, const Computer& cmp)
		{
			os << cmp.msp->m_make << '\t' <<
				cmp.msp->m_series << '\t' <<
				cmp.msp->m_processor << '\t' <<
				cmp.m_ram << '\t' <<
				cmp.m_hd << '\t' <<
				cmp.m_mon << '\n';

			return os;
		}
		static int count;
	};
	int Computer::count = 0;

	class Dummy
	{
	public:
		Dummy()
		{

		}
		~Dummy()
		{
			MSP::release();
		}
	}dummy;

	int main()
	{
		Computer c1("dell", "lattitude", "intel", "32gb", "1.5tb", "11inch");
		Computer c2("dell", "lattitude", "intel", "16gb", "2tb", "13inch");
		Computer c3("dell", "lattitude", "intel", "16gb", "1.5tb", "15inch");
		Computer c4("hp", "flash", "cellron", "32gb", "0.5tb", "11inch");
		Computer c5("dell", "lattitude", "cellron", "64gb", "0.5tb", "15inch");
		Computer c6("dell", "lattitude", "intel", "16gb", "2tb", "11inch");

		cout << c1 << c2 << c3 << c4 << c5 << c6 << '\n';
		cout << "Total Computer Ordered : " << Computer::count << '\n';
		cout << "Total MSP      Used    : " << MSP::count << '\n';
		return 0;
	}
}