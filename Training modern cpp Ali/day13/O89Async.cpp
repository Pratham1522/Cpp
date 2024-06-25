#include<iostream>
#include<string>
#include<thread>
#include<mutex>
#include<future>
#include<sstream>
using namespace std;
#define line(msg) cout<<"___________________"#msg"____________________\n"

namespace nm89
{
	string get_tid(std::thread::id id)
	{
		stringstream sst;
		sst << id;
		return sst.str();
	}

	int AddFun(int x, int y)
	{
		cout << "\t\t\t\tAddFun Tid = [ " + get_tid(this_thread::get_id()) + " ]\n";
		cout << "\t\t\t\tAddfun Started x = " + to_string(x) + " , y = " + to_string(y) + '\n';
		for (size_t i = 0; i < 10; i++)
		{
			cout << "\t\t\t\tAddfun Started\n";
			this_thread::sleep_for(chrono::seconds(1));
		}
		cout << "\t\t\t\tAddfun Completed\n";
		return x + y;
	}

	int main1()//snchronized call
	{
		cout << "Main Tid = [ " + get_tid(this_thread::get_id()) + " ]\n";
		int result = AddFun(10, 20);
		for (size_t i = 0; i < 10; i++)
		{
			cout << "Main Job...\n";
			this_thread::sleep_for(chrono::seconds(1));
		}
		cout << "result = " + to_string(result) + '\n';
		return 0;
	}

	void AddWrapper(promise<int>&& prom, int x, int y)
	{
		int result = AddFun(x, y);
		prom.set_value(result);
	}

	int main()//Asnchronized call
	{
		promise<int> addProm;
		future<int> addFut = addProm.get_future();
		cout << "Main Tid = [ " + get_tid(this_thread::get_id()) + " ]\n";
		thread t1(AddWrapper, std::move(addProm), 100, 200);
		for (size_t i = 0; i < 10; i++)
		{
			cout << "Main Job...\n";
			this_thread::sleep_for(chrono::seconds(1));
		}
		t1.join();
		int result = addFut.get();
		cout << "result = " + to_string(result) + '\n';
		return 0;
	}
}