#include<iostream>
#include<string>
using namespace std;

class IMsgSend
{
public:
	virtual void Send(string) = 0;
};

class NullSend:public IMsgSend
{
public:
	void Send(string) override
	{
		//do nothing
	}
};

class Helper :public IMsgSend
{
	IMsgSend* msg_send;
protected:
	Helper(IMsgSend* msg_send):msg_send(msg_send)//linked list construction
	{
	}
public:
	void Send(string msg) override //linked list traversal
	{
		msg_send->Send(msg);
	}
};


class Encryptor :public Helper
{
public:
	Encryptor(IMsgSend *msg_send):Helper(msg_send)
	{
	}
	void Send(string msg) override
	{
		msg = "ency - " + msg + " -ency";
		cout << "Encrpted : " << msg << '\n';
		Helper::Send(msg);
	}
};


class Encoder :public Helper
{
public:
	Encoder(IMsgSend* msg_send) :Helper(msg_send)
	{
	}
	void Send(string msg) override
	{
		msg = "ecod - " + msg + " -ecod";
		cout << "Encoder : " << msg << '\n';
		Helper::Send(msg);
	}
};


class Sign :public Helper
{
public:
	Sign(IMsgSend* msg_send) :Helper(msg_send)
	{
	}
	void Send(string msg) override
	{
		msg = "sin - " + msg + " -sin";
		cout << "Sign : " << msg << '\n';
		Helper::Send(msg);
	}
};

IMsgSend* Message_Factory()
{
	return new Encoder(new Encryptor(new Sign(new NullSend())));
}

int main()
{
	IMsgSend* msg = Message_Factory();
	msg->Send("India is great");

	return 0;
}