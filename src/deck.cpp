#include "deck.h"

Deck::Deck(const Card& card) : card(card) {}
int Deck::getValue() const { return card.value; }
