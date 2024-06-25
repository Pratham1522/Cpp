#include "Bussiness.hpp"

int main()
{
	string msg_from_service = "India won the test series";
    vector<string> infoRepo;

    start(msg_from_service, infoRepo);
    
    //print vector
	for (auto &entry : infoRepo)
	{
		cout << entry << '\n';
	}
	return 0;
}
