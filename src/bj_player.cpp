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
int BJPlayer::payout(float factor) {
  int earned = static_cast<int>(factor * static_cast<float>(bet));
  cash += earned;
  return -earned;
}

int BJPlayer::playRound(Deck& deck) {
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
int BJPlayer::getCash() const { return cash; }
void BJPlayer::resetBet() { bet = 0; }
