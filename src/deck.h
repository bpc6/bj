#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include <random>
#include <vector>

#include "card.h"

class Deck {
  std::vector<Card> cards;
  std::default_random_engine rng;

  static long epochTicks();

 public:
  Deck();
  Deck(const std::initializer_list<Card>& someCards);
  int size();
  void shuffle();
  Card& pop();
  Card& peek();
  void newDeckOrder();
  void push(Card card);
  Deck operator+(const Deck& other) const;
};

#endif  // BLACKJACK_DECK_H
