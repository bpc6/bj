#include <iostream>

#include "card.h"
#include "deck.h"

int main() {
  Card card{Card::Suit::DIAMOND, 4};
  std::cout << "card is " << card.getValue() << " of " << card.getSuit() << std::endl;

  Deck deck;
  std::cout << "deck's card has value " << deck.peek().getValue() << std::endl;
  return 0;
}
