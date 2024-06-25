#include<iostream>
using std::cout;

class Account    //database
{
	int _account_id { 0 };
	double total_balance { 0 };
public:
	Account(int id,double amount):_account_id(id), total_balance(amount){} //constructor 

	double getBalance() const { return total_balance; } //return balance

	void debit(double amount) { total_balance -= amount; } //credit
	void credit(double amount) { total_balance += amount; } //debit
};
