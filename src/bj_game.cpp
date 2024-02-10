#include "bj_game.h"

#include <memory>

void BJGame::playRound() {
  Deck deck;
  deck.shuffle();

  int dealerScore = dealer.playRound(deck);

  for (const auto& player : players) {
    player->placeBet();
    int playerScore = player->playRound(deck);
    int payout = player->payout(evaluateScoreFactor(playerScore, dealerScore));
    dealer.updateCash(payout);
    player->resetBet();
  }
}
BJGame::BJGame(int houseMoney) : dealer(BJDealer("dealer", houseMoney)) {}
void BJGame::addPlayer(const std::shared_ptr<BJPlayer>& p) { Game::addPlayer(p); }
void BJGame::removePlayer(const std::shared_ptr<BJPlayer>& p) { Game::removePlayer(p); }
void BJGame::playGame() { playRound(); }
float BJGame::evaluateScoreFactor(int playerScore, int dealerScore) {
  if (playerScore == dealerScore) {
    return 0;
  } else if (playerScore == 21) {
    return 1.5;
  } else if (playerScore > dealerScore) {
    return 1;
  }
  return -1;
}
int BJGame::getHouseMoney() { return dealer.getCash(); }
