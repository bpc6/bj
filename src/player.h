#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include <string>

class Player {
  std::string username;

 public:
  explicit Player(std::string usr);
  bool operator<(const Player& rhs) const;
  std::string getUsername();
};

#endif  // BLACKJACK_PLAYER_H
