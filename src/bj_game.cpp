#include "bj_game.h"

#include <iostream>
#include <memory>

void BJGame::playRound() {
  Deck deck;
  deck.shuffle();

  int dealerScore = dealer.playRound(deck);

  auto playerPtr = players.rbegin();
  if (playerPtr == players.rend()) {
    std::cout << "empty set, wtf" << std::endl;
  } else {
    std::cout << "player user: " << (*playerPtr)->getUsername() << std::endl;
  }

  for (const auto& player : players) {
    player->placeBet();
    int playerScore = player->playRound(deck);
    int payout = player->payout(evaluateScoreFactor(playerScore, dealerScore));
    dealer.updateCash(payout);
    player->resetBet();
  }
}
BJGame::BJGame(int houseMoney) : dealer(BJDealer("dealer", houseMoney)) {}
void BJGame::addPlayer(const std::shared_ptr<BJPlayer>& p) { players.insert(p); }
void BJGame::removePlayer(const std::shared_ptr<BJPlayer>& p) {
  auto it = players.find(p);
  if (it != players.end()) {
    players.erase(it);
  } else {
    std::string msg = "Player " + p->getUsername() + " was not in the game.";
    throw std::runtime_error(msg);
  }
}
int BJGame::numPlayers() { return static_cast<int>(players.size()); }
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
