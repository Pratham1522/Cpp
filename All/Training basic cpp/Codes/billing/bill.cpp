#include "bill.h"

bill::bill():billnumber(231),billamount(2000)
{
     customerinfo = customer();
     billdate = date();
}
bill::bill(int bnum,const char* nam,int dt,int mon,int yer,int bamn):billnumber(bnum),billamount(bamn)
{
     customerinfo = customer(nam);
     billdate = date(dt,mon,yer);
}

void bill::accept()
{
    std::cout<<"Enter billnumber"<<std::endl;
    std::cin>>billnumber;
    customerinfo.accept();
    billdate.accept();
    std::cout<<"Enter billamount"<<std::endl;
    std::cin>>billamount;

}

std::ostream& operator<<(std::ostream&out,bill &other)
{
    out<<"billnumber"<<std::endl;
    out<<other.billnumber;
    out<<other.customerinfo;
    out<<other.billdate;
    out<<"billamount"<<std::endl;
    out<<other.billamount<<std::endl;
    return out;
    
}

bool bill::find(const char *nm)
{
   if(!strcmp(nm,customerinfo.getCustomername())){
       return true;
   }
   return false;
}

bill::~bill()
{

}

