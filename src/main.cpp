#include <iostream>

#include "cli_player.h"
#include "game.h"

int main() {
  Game bj;
  bj.addPlayer(std::make_shared<CLIPlayer>());
  bj.playRound();

  return 0;
}
