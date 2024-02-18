#ifndef BLACKJACK_GAME_H
#define BLACKJACK_GAME_H
#include <memory>
#include <set>

#include "deck.h"
#include "player.h"

class Game {
  /**
   * Private class BJDealer is a BJPlayer who follows the dealer's rules
   */
  class BJDealer : public Player {
   public:
    using Player::Player;
    void placeBet() override { bet = 0; }
    bool hit() override { return score < 17; }
    void updateCash(int newCash) { cash += newCash; }
  };

  std::set<std::shared_ptr<Player>> players;
  BJDealer dealer;
  static float evaluateScoreFactor(int playerScore, int dealerScore);

 public:
  explicit Game(int houseMoney = 0);
  void addPlayer(const std::shared_ptr<Player>& p);
  void removePlayer(const std::shared_ptr<Player>& p);
  int numPlayers();
  void playRound();
  int getHouseMoney();
};

#endif  // BLACKJACK_GAME_H
