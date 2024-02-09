#include "bj_game.h"

#include <memory>
#include <utility>

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
BJGame::BJGame(int houseMoney, Deck deck) : houseMoney(houseMoney), deck(std::move(deck)) {}
void BJGame::addPlayer(const std::shared_ptr<BJPlayer>& p) { Game::addPlayer(p); }
void BJGame::removePlayer(const std::shared_ptr<BJPlayer>& p) { Game::removePlayer(p); }
void BJGame::playGame() {}
