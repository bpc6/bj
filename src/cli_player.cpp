#include "cli_player.h"

#include <iostream>

CLIPlayer::CLIPlayer() : Player("", 0) {
  std::cout << "Enter your username: ";
  std::cin >> username;

  std::cout << "Starting cash: ";
  std::cin >> cash;
}
void CLIPlayer::placeBet() {
  std::cout << "Place your bet: ";
  std::cin >> bet;
}
bool CLIPlayer::hit() {
  char userInput;
  std::cout << "Hit (h) or stay (s): ";
  std::cin >> userInput;
  if (userInput == 'h')
    return true;
  else if (userInput == 's')
    return false;
  std::cout << "Unrecognized request" << std::endl;
  return hit();
}
