#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <mutex>
using std::cout;
using std::string;
using std::vector;
using std::shared_future;
using std::lock_guard;
using std::thread;

std::mutex mut;
void Sender(std::promise<string> &&prom, string msg)
{
	prom.set_value(msg);
}

void Reciever1(vector<string> &repo, shared_future<string> fut)
{
	string msg = fut.get();
	msg = "rec1--" + msg + "--rec1";
	mut.lock();
	repo.push_back(msg);
	mut.unlock();
}

void Reciever2(vector<string> &repo, shared_future<string> fut)
{
	string msg = fut.get();
	msg = "rec2--" + msg + "--rec2";
	lock_guard<std::mutex> lock(mut);
	repo.push_back(msg);
}

void Reciever3(vector<string> &repo, shared_future<string> fut)
{
	string msg = fut.get();
	msg = "rec3--" + msg + "--rec3";
	lock_guard<std::mutex> lock(mut);
	repo.push_back(msg);
}
void start(string msg, vector<string>& infopile)
{
    std::promise<std::string> prom;
	shared_future<string> fut = prom.get_future();

	thread t1(&Sender, move(prom), msg);
	thread t2(&Reciever1, ref(infopile), fut);
	thread t3(&Reciever2, ref(infopile), fut);
	thread t4(&Reciever3, ref(infopile), fut);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
}
