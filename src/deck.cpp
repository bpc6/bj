#include "deck.h"

#include <algorithm>
#include <stdexcept>

using Suit = Card::Suit;

Deck::Deck() : rng(epochTicks()) { newDeckOrder(); }

Deck::Deck(const std::initializer_list<Card>& someCards) : cards(someCards), rng(epochTicks()) {}

int Deck::size() { return static_cast<int>(cards.size()); }

void Deck::shuffle() { std::shuffle(cards.begin(), cards.end(), rng); }

Card& Deck::pop() {
  Card& back = peek();
  cards.pop_back();
  return back;
}

Card& Deck::peek() {
  if (cards.empty()) throw std::out_of_range("Tried to access a card in an empty deck!");
  return cards.back();
}

void Deck::newDeckOrder() {
  cards.clear();
  for (Suit suit : {Suit::SPADE, Suit::CLUB}) {
    for (int i = 1; i <= 13; i++) {
      cards.emplace_back(suit, i);
    }
  }
  for (Suit suit : {Suit::DIAMOND, Suit::HEART}) {
    for (int i = 13; i > 0; i--) {
      cards.emplace_back(suit, i);
    }
  }
}

long Deck::epochTicks() {
  return std::chrono::high_resolution_clock::now().time_since_epoch().count();
}

void Deck::push(Card card) { cards.push_back(card); }

Deck Deck::operator+(const Deck& other) const {
  Deck combinedDeck(*this);
  combinedDeck.cards.insert(combinedDeck.cards.end(), other.cards.begin(), other.cards.end());
  return combinedDeck;
}
