#include <iostream>
#include <map>
#include <thread>
#include <future>
#include <mutex>
using namespace std;

mutex mut;
void Origin(promise<string> &&prom, string msg)
{
	msg = "Origin - " + msg + "--Origin";
	prom.set_value(msg);
}
void Target1(int key, map<int, string> &repo, shared_future<string> fut)
{
	string msg = fut.get();
	msg = "t1-" + msg + "-t1";
	mut.lock();
	// lock_guard<mutex> lock(mut);
	repo[key] = msg;
	mut.unlock();
}
void Target2(int key, map<int, string> &repo, shared_future<string> fut)
{
	string msg = fut.get();
	msg = "t1-" + msg + "-t1";
	lock_guard<mutex> lock(mut);
	repo[key] = msg;
}
void Target3(int key, map<int, string> &repo, shared_future<string> fut)
{
	string msg = fut.get();
	msg = "t1-" + msg + "-t1";
	lock_guard<mutex> lock(mut);
	repo[key] = msg;
}
int main()
{
	string msg = "Kill him not let him live";
	map<int, string> repo;

	promise<string> prom;
	shared_future<string> fut = prom.get_future();

	thread t1(&Origin, move(prom), msg);
	thread t2(&Target1, 10, ref(repo), fut);
	thread t3(&Target2, 20, ref(repo), fut);
	thread t4(&Target3, 30, ref(repo), fut);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	for (auto &[k, v] : repo)
	{
		cout << k << '\t' << v << '\n';
	}
	return 0;
}
