#ifndef BLACKJACK_BJ_CAREFUL_PLAYER_H
#define BLACKJACK_BJ_CAREFUL_PLAYER_H

#include "bj_player.h"

/**
 * Careful player puts $1 down and never hits
 */
class BJCarefulPlayer : public BJPlayer {
  void placeBet() override;
  bool hit() override;
};

#endif  // BLACKJACK_BJ_CAREFUL_PLAYER_H
