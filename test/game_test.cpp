#include "game.h"

#include "gtest/gtest.h"

class FakeGame : public Game {
  void playGame() override {}
};

TEST(GameTest, AddPlayer) {
  FakeGame game;
  game.addPlayer(std::make_shared<Player>("username"));
  EXPECT_EQ(game.numPlayers(), 1);
}

TEST(GameTest, RemovePlayer) {
  FakeGame game;
  auto playerPtr = std::make_shared<Player>("username");
  game.addPlayer(playerPtr);

  game.removePlayer(playerPtr);
  EXPECT_EQ(game.numPlayers(), 0);
}

TEST(GameTest, RemoveWithNoPlayers) {
  FakeGame game;
  auto playerPtr = std::make_shared<Player>("username");
  ASSERT_THROW(game.removePlayer(playerPtr), std::runtime_error);
}
