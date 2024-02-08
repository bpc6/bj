#include "bj_player.h"

void BJPlayer::initializeRound(Card& c0, Card& c1) {
  placeBet();
  takeCard(c0);
  takeCard(c1);
}
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
int BJPlayer::bust() { return 0; }
void BJPlayer::placeBet() { bet = 0; }  // TODO make pure virtual and fake for testing
bool BJPlayer::hit() { return false; }  // TODO same
