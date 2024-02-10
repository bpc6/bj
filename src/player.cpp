#include "player.h"

#include <utility>

bool Player::operator<(const Player& rhs) const { return this->username < rhs.username; }
Player::Player(std::string usr) : username(std::move(usr)) {}
std::string Player::getUsername() { return username; }
