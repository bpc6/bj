#ifndef BLACKJACK_BJ_PLAYER_H
#define BLACKJACK_BJ_PLAYER_H
#include <vector>

#include "card.h"
#include "player.h"

class BJPlayer : public Player {
  int cash = 0;
  std::vector<Card> cards;
  int score = 0;
  int aceCount = 0;

  void updateScore(int val);

 protected:
  int bet = 0;

 public:
  static const int MAX_SCORE = 21;
  void initializeRound(Card& c0, Card& c1);
  void takeCard(const Card& c);

  virtual void placeBet() = 0;
  virtual bool hit() = 0;
  int bust();
  [[nodiscard]] int getScore() const;
};

#endif  // BLACKJACK_BJ_PLAYER_H
