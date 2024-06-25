#include<iostream>
#include<string>
#include<thread>
#include<mutex>
#include<future>
#include<sstream>
using namespace std;
#define line(msg) cout<<"___________________"#msg"____________________\n"
namespace nm90
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

	int main()//Asnchronized call
	{
		future<int> fut = std::async(AddFun, 10, 20);
		//future<int> fut=std::async(std::launch::async,AddFun, 10, 20);
		//future<int> fut=std::async(std::launch::deferred,AddFun, 10, 20);
		cout << "Main Tid = [ " + get_tid(this_thread::get_id()) + " ]\n";
		for (size_t i = 0; i < 3; i++)
		{
			cout << "Main Job...\n";
			this_thread::sleep_for(chrono::seconds(1));
		}
		int result = fut.get();
		cout << "result = " + to_string(result) + '\n';
		return 0;
	}
}