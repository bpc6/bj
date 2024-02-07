#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include <vector>

#include "card.h"

class Deck {
  std::vector<Card> cards;

 public:
  Deck();
  void shuffle();
  Card& pop();
  Card& peek();
  void newDeckOrder();
};

#endif  // BLACKJACK_DECK_H
