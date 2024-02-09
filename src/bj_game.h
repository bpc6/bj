#ifndef BLACKJACK_BJ_GAME_H
#define BLACKJACK_BJ_GAME_H

#include "bj_player.h"
#include "deck.h"
#include "game.h"

class BJGame : public Game {
  std::set<std::shared_ptr<BJPlayer>> players;
  int houseMoney;

 public:
  void addPlayer(const std::shared_ptr<BJPlayer>& p);
  void removePlayer(const std::shared_ptr<BJPlayer>& p);

  void playRound();
};

#endif  // BLACKJACK_BJ_GAME_H
