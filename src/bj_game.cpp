#include "bj_game.h"

#include <memory>

void BJGame::playRound() {
  //  Deck deck;
  //  deck.shuffle();
  //
  //  for (auto player : players) {
  //    player->initializeRound(deck.pop(), deck.pop());
  //  }
  //  // todo update view?
  //  for (auto player : players) {
  //    while (player->hit()) {
  //      player->takeCard(deck.pop());
  //      if (player->getScore() > BJPlayer::MAX_SCORE) {
  //        houseMoney += player->bust();
  //        break;
  //      }
  //    }
  //  }
}
void BJGame::addPlayer(const std::shared_ptr<BJPlayer>& p) { Game::addPlayer(p); }
void BJGame::removePlayer(const std::shared_ptr<BJPlayer>& p) { Game::removePlayer(p); }
