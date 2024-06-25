#include <iostream>

class Snippets
{
private:
    int _id;

public:
    Snippets() = default;                           // Default constructor
    Snippets(const Snippets &) = default;           // Copy constructor
    Snippets &operator=(const Snippets &) = delete; // Copy assignment operator
    Snippets(Snippets &&) = default;                // Move constructor
    Snippets &operator=(Snippets &&) = delete;      // Move assignment operator
    ~Snippets() = default;                          // Destructor
    explicit Snippets(int id) : _id{id} {}

    friend std::ostream &operator<<(std::ostream &os, const Snippets &rhs)
    {
        os << "_id: " << rhs._id;
        return os;
    }
};

Snippets Magic()
{
    Snippets s(101);
    return s;
}

int main()
{
    // s is of type snippets and will be asisned to whatever assinged from magic.
    Snippets s = Magic();
    std::cout << s << std::endl;
}

/*
    C Language
    Magic                 Main
    [101]    ------->      [101]
    4bytes                 4bytes
    [100hX09]               [101xh]


    CPP
    Magic    -------->       Main

     D       -------->        d1

    [101]                     [101]
    0x101H                   4bytes[0x99H]

    
   
    Modern CPP [Guranteed with CPP 17]

    Magic                     Main
                               d1
     101 ------------->        []
                              4 bytes
                              0x99h

                              std::cout<<d1;                  

*/