#include<iostream>
using namespace std;
#define line(msg) cout<<"____________________"#msg"______________________\n"

namespace nm60
{
	typedef void (*FPTR)();

	void WriteFile()
	{
		cout << "WriteFile\n";
	}
	void FileClose()
	{
		cout << "FileClose\n";
	}
	FPTR FileOpen()
	{
		cout << "FileOpen\n";
		return &FileClose;
	}

	/*
	FileOpen  @1
	WriteFile @2
	*/

	//------------------------------------
	int main1()
	{
		FPTR fp = FileOpen();
		WriteFile();
		WriteFile();
		WriteFile();
		fp();
		return 0;
	}





	void Apple()
	{
		cout << "Apple\n";
	}
	void Pine()
	{
		cout << "Pine\n";
	}
	FPTR  Orange(FPTR fp)
	{
		fp();
		cout << "Orange\n";
		fp();
		return Pine;
	}
	void Fruit(FPTR fp)
	{
		cout << "Mango\n";
		fp();
		cout << "Jack\n";
	}

	int main()
	{
		Fruit(Orange(Apple));
		return 0;
	}

}