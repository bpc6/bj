#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include <vector>

#include "card.h"

class Deck {
  std::vector<Card> cards;

 public:
  Deck();
  Deck(const std::initializer_list<Card>& someCards);
  int size();
  void shuffle();
  Card& pop();
  Card& peek();
  void newDeckOrder();
  void sort();
};

#endif  // BLACKJACK_DECK_H
