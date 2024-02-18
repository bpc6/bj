#ifndef BLACKJACK_CLI_PLAYER_H
#define BLACKJACK_CLI_PLAYER_H

#include "player.h"

class CLIPlayer : public Player {
 public:
  CLIPlayer();
  void placeBet() override;
  bool hit() override;
};

#endif  // BLACKJACK_CLI_PLAYER_H
