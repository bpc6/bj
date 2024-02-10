#ifndef BLACKJACK_GAME_H
#define BLACKJACK_GAME_H

#include <memory>
#include <set>

#include "player.h"

class Game {
 protected:
  std::set<std::shared_ptr<Player>> players;

 public:
  void addPlayer(const std::shared_ptr<Player>& p);
  void removePlayer(const std::shared_ptr<Player>& p);
  int numPlayers();
  virtual void playGame() = 0;
};

#endif  // BLACKJACK_GAME_H
