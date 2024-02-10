#include "bj_game.h"

#include "gtest/gtest.h"

/**
 * Concrete BJPlayer just for testing. Careful player always bets 1 and never hits.
 */
class BJCarefulPlayer : public BJPlayer {
 public:
  BJCarefulPlayer(const std::string& usr, int cash) : BJPlayer(usr, cash) {}
  void placeBet() override { bet = 2; }
  bool hit() override { return false; }
};

TEST(BJGameTest, AddAndRemovePlayer) {
  BJGame game;
  auto p = std::make_shared<BJCarefulPlayer>("username", 10);

  game.addPlayer(p);
  EXPECT_EQ(game.numPlayers(), 1);

  game.removePlayer(p);
  EXPECT_EQ(game.numPlayers(), 0);
}
