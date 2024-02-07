#include <iostream>

#include "card.h"

int main() {
  Card card{Card::Suit::DIAMOND, 4};
  std::cout << "card is " << card.value << " of " << card.suit << std::endl;
  return 0;
}
