#include <iostream>

#include "card.h"
#include "deck.h"

int main() {
  Card card{Card::Suit::DIAMOND, 4};
  std::cout << "card is " << card.getValue() << " of " << card.getSuit() << std::endl;

  Deck deck;
  deck.shuffle();
  auto top = deck.peek();
  std::cout << "top card: " << top.getValue() << " of " << top.getSuit() << std::endl;
  return 0;
}
