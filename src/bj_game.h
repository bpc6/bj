#ifndef BLACKJACK_BJ_GAME_H
#define BLACKJACK_BJ_GAME_H

#include "bj_player.h"
#include "deck.h"
#include "game.h"

class BJGame : public Game {
  std::set<std::shared_ptr<BJPlayer>> players;
  int houseMoney;

 public:
  explicit BJGame(int houseMoney = 0);
  void addPlayer(const std::shared_ptr<BJPlayer>& p);
  void removePlayer(const std::shared_ptr<BJPlayer>& p);
  void playGame() override;

  void playRound();
  void playRoundWithDeck(Deck& deck);
};

#endif  // BLACKJACK_BJ_GAME_H
