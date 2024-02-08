#include "player.h"

bool Player::operator<(const Player& rhs) const { return this->username < rhs.username; }
Player::Player(const std::string& usr) : username(usr) {}
