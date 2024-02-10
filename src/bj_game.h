#ifndef BLACKJACK_BJ_GAME_H
#define BLACKJACK_BJ_GAME_H

#include "bj_player.h"
#include "deck.h"
#include "game.h"

class BJGame : public Game {
  /**
   * Private class BJDealer is a BJPlayer who follows the dealer's rules
   */
  class BJDealer : public BJPlayer {
   public:
    using BJPlayer::BJPlayer;
    void placeBet() override { bet = 0; }
    bool hit() override { return score < 17; }
    void updateCash(int newCash) { cash += newCash; }
  };

  std::set<std::shared_ptr<BJPlayer>> players;
  BJDealer dealer;
  static float evaluateScoreFactor(int playerScore, int dealerScore);

 public:
  explicit BJGame(int houseMoney = 0);
  void addPlayer(const std::shared_ptr<BJPlayer>& p);
  void removePlayer(const std::shared_ptr<BJPlayer>& p);
  void playGame() override;
  void playRound();
  int getHouseMoney();
};

#endif  // BLACKJACK_BJ_GAME_H
