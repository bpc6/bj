#include "player.h"

#include <utility>

Player::Player(std::string usr, int cash) : username(std::move(usr)), cash(cash) {}

void Player::takeCard(const Card& c) {
  updateScore(c.getValue());
  cards.push_back(c);
}
void Player::updateScore(int val) {
  score += (val == 1) ? 11 : std::min(val, 10);
  aceCount += (val == 1);
  for (int i = 0; i < aceCount; i++) {
    if (score > MAX_SCORE) {
      score -= 10;
    }
  }
}
int Player::getScore() const { return score; }
int Player::payout(float factor) {
  int earned = static_cast<int>(factor * static_cast<float>(bet));
  cash += earned;
  return -earned;
}

int Player::playRound(Deck& deck) {
  takeCard(deck.pop());
  takeCard(deck.pop());

  while (hit()) {
    takeCard(deck.pop());
    if (score > MAX_SCORE) {
      return 0;
    }
  }
  return score;
}
int Player::getCash() const { return cash; }
void Player::resetBet() { bet = 0; }

bool Player::operator<(const Player& rhs) const { return this->username < rhs.username; }
std::string Player::getUsername() { return username; }
