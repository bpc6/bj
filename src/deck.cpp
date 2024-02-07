#include "deck.h"

#include <stdexcept>

using Suit = Card::Suit;

Deck::Deck() { newDeckOrder(); }

Deck::Deck(const std::initializer_list<Card>& someCards) : cards(someCards) {}

int Deck::size() { return static_cast<int>(cards.size()); }

void Deck::shuffle() {}

void Deck::sort() {}

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
      cards.emplace_back(Card{suit, i});
    }
  }
  for (Suit suit : {Suit::DIAMOND, Suit::HEART}) {
    for (int i = 13; i > 0; i--) {
      cards.emplace_back(Card{suit, i});
    }
  }
}
