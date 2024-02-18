#include "game.h"

#include "gtest/gtest.h"

/**
 * Concrete BJPlayer just for testing. Careful player always bets 1 and never hits.
 */
class BJCarefulPlayer : public Player {
 public:
  BJCarefulPlayer(const std::string& usr, int cash) : Player(usr, cash) {}
  void placeBet() override { bet = 2; }
  bool hit() override { return false; }
};

TEST(BJGameTest, AddAndRemovePlayer) {
  Game game;
  auto p = std::make_shared<BJCarefulPlayer>("username", 10);

  game.addPlayer(p);
  EXPECT_EQ(game.numPlayers(), 1);

  game.removePlayer(p);
  EXPECT_EQ(game.numPlayers(), 0);
}

TEST(BJGameTest, PlayRound) {
  Game game;
  game.addPlayer(std::make_shared<BJCarefulPlayer>("username", 10));
  EXPECT_EQ(game.numPlayers(), 1);
  int initialMoney = game.getHouseMoney();

  game.playRound();
  EXPECT_NE(game.getHouseMoney(), initialMoney);
}
