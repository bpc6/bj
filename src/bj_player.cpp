#include "bj_player.h"

BJPlayer::BJPlayer(const std::string& usr, int cash) : Player(usr), cash(cash) {}

void BJPlayer::takeCard(const Card& c) {
  updateScore(c.getValue());
  cards.push_back(c);
}
void BJPlayer::updateScore(int val) {
  score += (val == 1) ? 11 : std::min(val, 10);
  aceCount += (val == 1);
  for (int i = 0; i < aceCount; i++) {
    if (score > MAX_SCORE) {
      score -= 10;
    }
  }
}
int BJPlayer::getScore() const { return score; }
bool BJPlayer::bust() const { return score > MAX_SCORE; }
int BJPlayer::cashOnHand() const { return cash; }
int BJPlayer::payout(float factor) {
  int earned = static_cast<int>(factor * static_cast<float>(bet));
  bet = 0;
  cash += earned;
  return -earned;
}
