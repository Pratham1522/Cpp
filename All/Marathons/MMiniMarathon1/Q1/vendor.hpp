#pragma once
#include<iostream>
#include<map>
using std::cout;
using std::string;
using std::map;

class Vendor //complete
{
private:
    string _vendor_id;
    double _vendor_charges;

public:
    Vendor(string v_id, int charge):_vendor_id(v_id),_vendor_charges(charge){} //constructor

    string getvendorId() const { return _vendor_id; }

    int getVendorCharges() const { return _vendor_charges; }
    void setVendorCharges(int vendor_charges) { _vendor_charges = vendor_charges; }

};



class VendorRepository
{
    static map<string, Vendor*> repo;

    public:
    static void Register (Vendor* v)
    {
        repo[v->getvendorId()]=v;
    }
    static void unRegister(string v_id)
    {
        // return repo[v_id];  //change to delete
        delete repo[v_id];
        repo.erase(v_id);
    }
    void clear()
    {
        for(auto rng : repo){
            string id=rng.first;
            delete repo[id];
            repo.erase(id);
        }
    }

};
map<string, Vendor*> VendorRepository::repo;