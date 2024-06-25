#ifndef DEBITCARD_H
#define DEBITCARD_H
#include "DebitCardType.h"

#include<iostream>

class DebitCard
{
private:
    short _cardCVV;
    long long _cardNumber;
    std::string _cardExpiry;
    DebitCardType _cardType;
public:
    DebitCard() = delete; //default constructor
    DebitCard(const DebitCard&) = delete; //copy constructor
    DebitCard& operator=(const DebitCard&) = delete; //operator overloading
    ~DebitCard() = default; //destructor
    DebitCard(DebitCard&&) = delete; //move constructor
    DebitCard& operator=(DebitCard&&) = delete; //move assignment

    DebitCard(short cvv, long long number, std::string expiry, DebitCardType _cardType);

    short cardCVV() const { return _cardCVV; }

    long long cardNumber() const { return _cardNumber; }

    std::string cardExpiry() const { return _cardExpiry; }

    friend std::ostream &operator<<(std::ostream &os, const DebitCard &rhs);
};

#endif // DEBITCARD_H
