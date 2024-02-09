#include "bj_game.h"

#include "gtest/gtest.h"

class BJNHitPlayer : public BJPlayer {
  int maxHits;
  int numHits = 0;

 public:
  BJNHitPlayer(const std::string& usr, int cash, int maxHits)
      : BJPlayer(usr, cash), maxHits(maxHits) {}
  void placeBet() override { bet = 2; }
  bool hit() override { return numHits++ < maxHits; }
};

TEST(BJGameTest, AddAndRemovePlayer) {
  BJGame game;
  auto p = std::make_shared<BJNHitPlayer>("3hits", 10, 3);

  game.addPlayer(p);
  EXPECT_EQ(game.numPlayers(), 1);

  game.removePlayer(p);
  EXPECT_EQ(game.numPlayers(), 0);
}
