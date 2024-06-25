#include<iostream>
#include<string>
#include<thread>
#include<mutex>
#include<future>
#include<sstream>
using namespace std;
#define line(msg) cout<<"___________________"#msg"____________________\n"

namespace nm91
{
	string get_tid(std::thread::id id)
	{

		stringstream sst;
		sst << id;
		return sst.str();
	}


	int main1()
	{
		std::async(std::launch::async, []() {this_thread::sleep_for(chrono::seconds(3)); cout << "Apple\n"; });
		std::async(std::launch::async, []() {this_thread::sleep_for(chrono::seconds(5)); cout << "orange\n"; });
		std::async(std::launch::async, []() {this_thread::sleep_for(chrono::seconds(2)); cout << "pine\n"; });

		return 0;
	}


	int main2()
	{
		future<void> f1 = std::async(std::launch::async, []() {this_thread::sleep_for(chrono::seconds(3)); cout << "Apple\n"; });
		future<void> f2 = std::async(std::launch::async, []() {this_thread::sleep_for(chrono::seconds(5)); cout << "orange\n"; });
		future<void> f3 = std::async(std::launch::async, []() {this_thread::sleep_for(chrono::seconds(2)); cout << "pine\n"; });


		return 0;
	}

	int main3()
	{
		future<void> f1 = std::async(std::launch::deferred | std::launch::async, []() {cout << "Apple11\n"; this_thread::sleep_for(chrono::seconds(3)); cout << "Apple\n"; });
		future<void> f2 = std::async(std::launch::deferred | std::launch::async, []() {cout << "Orange2\n"; this_thread::sleep_for(chrono::seconds(5)); cout << "orange\n"; });
		future<void> f3 = std::async(std::launch::deferred | std::launch::async, []() {cout << "Pine3\n"; this_thread::sleep_for(chrono::seconds(2)); cout << "pine\n"; });
		cout << "wait1\n";
		f1.get();
		cout << "wait2\n";
		f2.get();
		cout << "wait3\n";
		f3.get();
		return 0;
	}



	int main()
	{	
		cout << "Main tid = " + get_tid(this_thread::get_id()) + '\n';

		auto f1 = std::async([]() {std::launch::deferred | std::launch::async, this_thread::sleep_for(chrono::seconds(3)); cout << "Apple " + get_tid(this_thread::get_id()) + '\n'; });
		auto f2 = std::async([]() {std::launch::deferred | std::launch::async, this_thread::sleep_for(chrono::seconds(5)); cout << "orange " + get_tid(this_thread::get_id()) + '\n'; });
		auto f3 = std::async([]() {std::launch::deferred | std::launch::async, this_thread::sleep_for(chrono::seconds(2)); cout << "pine " + get_tid(this_thread::get_id()) + '\n'; });

		return 0;
	}

}