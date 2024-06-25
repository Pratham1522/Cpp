#include<iostream>
using namespace std;
#define line(msg) cout<<"___________________"msg"____________________\n"
/*

IEAudio  IEVideo  IEMagnifier

ChromeAudio  ChromeVideo  ChromeMagnifier

OperaAudio  OperaVideo  OperaMagnifier

//are components needed for functioning , and you have made classes for that,main dont know which object will come, but main should handle any requirement. 

*/

class IAudio  //abstract classes/
{
public:
	virtual void createAudio() = 0;
	virtual void attachAudio() = 0;
};
class IVideo
{
public:
	virtual void createVideo() = 0;
	virtual void attachVideo() = 0;
};
class IMag
{
public:
	virtual void createMag() = 0;
	virtual void attachMag() = 0;
};
//factory : consumer dont know the obj, whatever comes factory have to use it.
class IFactory
{
public:
	virtual IAudio* getAudio() = 0;
	virtual IVideo* getVideo() = 0;
	virtual IMag* getMag() = 0;
};


class IEAudio:public IAudio
{
public:
	 void createAudio() override { cout << "IE Audio created\n"; }
	 void attachAudio() override { cout << "IE Audio attached\n"; }
};

class IEVideo:public IVideo
{
public:
	 void createVideo() override { cout << "IE Video created\n"; }
	 void attachVideo() override { cout << "IE Video attached\n"; }
};

class IEMag:public IMag
{
public:
	void createMag() override { cout << "IE Mag created\n"; }
	void attachMag() override { cout << "IE Mag attached\n"; }
};

class IEFactory:public IFactory
{
public:
	IAudio* getAudio() override {
		return new IEAudio();
	}
	IVideo* getVideo() override { 
		return new IEVideo(); 
	}
	 IMag* getMag() override { 
		 return new IEMag(); 
	 }
};


class ChromeAudio :public IAudio
{
public:
	void createAudio() override { cout << "Chrome Audio created\n"; }
	void attachAudio() override { cout << "Chrome Audio attached\n"; }
};

class ChromeVideo :public IVideo
{
public:
	void createVideo() override { cout << "Chrome Video created\n"; }
	void attachVideo() override { cout << "Chrome Video attached\n"; }
};

class ChromeMag :public IMag
{
public:
	void createMag() override { cout << "Chrome Mag created\n"; }
	void attachMag() override { cout << "Chrome Mag attached\n"; }
};

class ChromeFactory :public IFactory
{
public:
	IAudio* getAudio() override {
		return new ChromeAudio();
	}
	IVideo* getVideo() override {
		return new ChromeVideo();
	}
	IMag* getMag() override {
		return new ChromeMag();
	}
};
class OperaAudio :public IAudio
{
public:
	void createAudio() override { cout << " Audio created\n"; }
	void attachAudio() override { cout << " Audio attached\n"; }
};

class OperaVideo :public IVideo
{
public:
	void createVideo() override { cout << " Video created\n"; }
	void attachVideo() override { cout << " Video attached\n"; }
};

class OperaMag :public IMag
{
public:
	void createMag() override { cout << "Chag created\n"; }
	void attachMag() override { cout << "Chag attached\n"; }
};

class OperaFactory :public IFactory
{
public:
	IAudio* getAudio() override {
		return new OperaAudio();
	}
	IVideo* getVideo() override {
		return new OperaVideo();
	}
	IMag* getMag() override {
		return new OperaMag();
	}
};

class FactoryDecider
{
public:
	static IFactory* getFactory(int choice = 10)
	{
		if (10 == choice)
		{
			return new IEFactory();
		}
		else if (20 == choice)
		{
			return new ChromeFactory();

		}
		else if (30 == choice)
		{
			return new OperaFactory();

		}
			return nullptr;
	}

};
int main()
{
	IFactory* factory = FactoryDecider::getFactory(10);
	IAudio* audio = factory->getAudio();
	audio->createAudio();
	audio->attachAudio();
	IVideo* video = factory->getVideo();
	video->createVideo();
	video->attachVideo();
	IMag* mag = factory->getMag();
	mag->createMag();
	mag->attachMag();

	return 0;
}
//abstract factory design pattern : switiching between family/home/kpit/Downloads/O55Problem.cpp