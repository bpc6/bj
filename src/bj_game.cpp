#include "bj_game.h"

#include <memory>

void BJGame::playRound() {
  Deck deck;
  deck.shuffle();

  for (const auto& player : players) {
    player->placeBet();
    int playerScore = player->playRound(deck);
    // compare to dealer score
  }
}
BJGame::BJGame(int houseMoney) : houseMoney(houseMoney) {}
void BJGame::addPlayer(const std::shared_ptr<BJPlayer>& p) { Game::addPlayer(p); }
void BJGame::removePlayer(const std::shared_ptr<BJPlayer>& p) { Game::removePlayer(p); }
void BJGame::playGame() { playRound(); }
