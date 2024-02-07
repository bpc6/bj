#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include "card.h"

class Deck {
  Card card;

 public:
  explicit Deck(const Card& card);
  int getValue() const;
};

#endif  // BLACKJACK_DECK_H
