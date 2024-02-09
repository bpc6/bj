#include "game.h"

#include <stdexcept>

void Game::addPlayer(const std::shared_ptr<Player>& p) { players.insert(p); }
void Game::removePlayer(const std::shared_ptr<Player>& p) {
  auto it = players.find(p);
  if (it != players.end()) {
    players.erase(it);
  } else {
    std::string msg = "Player " + p->getUsername() + " was not in the game.";
    throw std::runtime_error(msg);
  }
}
int Game::numPlayers() { return static_cast<int>(players.size()); }
