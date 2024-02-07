#include "deck.h"

using Suit = Card::Suit;

Deck::Deck() { newDeckOrder(); }

void Deck::shuffle() {}

Card& Deck::pop() {
  Card& back = peek();
  cards.pop_back();
  return back;
}
Card& Deck::peek() { return cards.back(); }

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
