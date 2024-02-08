#ifndef BLACKJACK_BJ_PLAYER_H
#define BLACKJACK_BJ_PLAYER_H
#include <vector>

#include "card.h"
#include "player.h"

class BJPlayer : public Player {
  int cash = 0;
  int bet = 0;
  std::vector<Card> cards;
  int score = 0;
  int aceCount = 0;

  void updateScore(int val);

 public:
  static const int MAX_SCORE = 21;
  void initializeRound(Card& c0, Card& c1);
  void takeCard(const Card& c);

  virtual void placeBet();
  virtual bool hit();
  int bust();
  [[nodiscard]] int getScore() const;
};

#endif  // BLACKJACK_BJ_PLAYER_H
