#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H

class Card {
 public:
  enum Suit { SPADE, CLUB, DIAMOND, HEART };
  Card(Suit suit, int value);
  [[nodiscard]] Suit getSuit() const;
  [[nodiscard]] int getValue() const;

 private:
  Suit suit;
  int value;
};

#endif  // BLACKJACK_CARD_H
