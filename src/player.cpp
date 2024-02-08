#include "player.h"

bool Player::operator<(const Player& rhs) const { return this->username < rhs.username; }
