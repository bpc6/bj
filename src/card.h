#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H

struct Card {
  enum Suit { HEART, DIAMOND, SPADE, CLUB };

  const Suit suit;
  const int value;
};

#endif  // BLACKJACK_CARD_H
