#include <iostream>

#include "bj_cli_player.h"
#include "bj_game.h"

int main() {
  BJGame bj;
  bj.addPlayer(std::make_shared<BJCLIPlayer>());
  bj.playGame();

  return 0;
}
