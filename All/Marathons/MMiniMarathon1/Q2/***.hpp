#include "transHelper.hpp"
#define line(msg) cout<<"--------x--------"#msg"--------x--------\n"
void Init()
{
    line(start);
    Account acc(001, 100000);
	TransHelper trans(acc);
    cout << "balance : " << trans.getBalance() << '\n';
	trans.credit(13000);
	trans.credit(2400);
	trans.credit(37000);

	cout << "balance : " << trans.getBalance() << '\n';
	trans.debit(40000);
	trans.debit(1500);
	cout << "balance : " << trans.getBalance() << '\n';
	trans.undo();
	trans.undo();
	trans.undo();
	cout << "balance : " << trans.getBalance() << '\n';
    line(xx_end_xx);
}