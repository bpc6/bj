#include "card.h"

Card::Suit Card::getSuit() const { return suit; }
int Card::getValue() const { return value; }
Card::Card(Card::Suit suit, int value) : suit(suit), value(value) {}
