#ifndef BLACKJACK_BJ_PLAYER_H
#define BLACKJACK_BJ_PLAYER_H
#include <vector>

#include "card.h"
#include "deck.h"

class BJPlayer {
  static const int MAX_SCORE = 21;
  std::vector<Card> cards;
  int aceCount = 0;

  void updateScore(int val);
  bool operator<(const BJPlayer& rhs) const;

 protected:
  std::string username;
  int bet = 0;
  int score = 0;
  int cash = 0;

 public:
  BJPlayer(std::string usr, int cash);
  void takeCard(const Card& c);

  virtual void placeBet() = 0;
  virtual bool hit() = 0;
  int payout(float factor);
  void resetBet();
  [[nodiscard]] int getScore() const;
  int playRound(Deck& deck);
  [[nodiscard]] int getCash() const;
  std::string getUsername();
};

#endif  // BLACKJACK_BJ_PLAYER_H
