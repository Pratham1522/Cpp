#include "DebitCard.h"

DebitCard::DebitCard(short cvv, long long number, std::string expiry, DebitCardType cardType)
    :_cardCVV{cvv}, _cardNumber{number}, _cardExpiry{expiry}, _cardType{cardType}
{
}
std::ostream &operator<<(std::ostream &os, const DebitCard &rhs) {
    os << "_cardCVV: " << rhs._cardCVV
       << " _cardNumber: " << rhs._cardNumber
       << " _cardExpiry: " << rhs._cardExpiry
       << " _cardType: " << static_cast<int>(rhs._cardType);
    return os;
}
