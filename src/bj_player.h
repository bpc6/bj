#ifndef BLACKJACK_BJ_PLAYER_H
#define BLACKJACK_BJ_PLAYER_H
#include <vector>

#include "card.h"
#include "deck.h"
#include "player.h"

class BJPlayer : public Player {
  int cash = 0;
  std::vector<Card> cards;
  int score = 0;
  int aceCount = 0;
  static const int MAX_SCORE = 21;

  void updateScore(int val);

 protected:
  int bet = 0;

 public:
  BJPlayer(const std::string& usr, int cash);
  void takeCard(const Card& c);

  virtual void placeBet() = 0;
  virtual bool hit() = 0;
  int payout(float factor);
  [[nodiscard]] int getScore() const;
  [[nodiscard]] int cashOnHand() const;
  int playRound(Deck& deck);
};

#endif  // BLACKJACK_BJ_PLAYER_H
