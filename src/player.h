#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include <string>

class Player {
  std::string username;

 public:
  explicit Player(const std::string& usr);
  bool operator<(const Player& rhs) const;
};

#endif  // BLACKJACK_PLAYER_H
