#include <iostream>

#include "bj_cli_player.h"
#include "game.h"

int main() {
  Game bj;
  bj.addPlayer(std::make_shared<BJCLIPlayer>());
  bj.playGame();

  return 0;
}
