#include "bj_player.h"

#include "card.h"
#include "gtest/gtest.h"

TEST(BJPlayerTest, BasicScore) {
  BJPlayer player;
  EXPECT_EQ(player.getScore(), 0);

  player.takeCard(Card{Card::HEART, 4});
  EXPECT_EQ(player.getScore(), 4);
}

TEST(BJPlayerTest, FaceCard) {
  BJPlayer player;

  player.takeCard(Card{Card::HEART, 12});
  EXPECT_EQ(player.getScore(), 10);
}

TEST(BJPlayerTest, AceIs1) {
  BJPlayer player;

  player.takeCard(Card{Card::HEART, 12});
  player.takeCard(Card{Card::HEART, 8});
  player.takeCard(Card{Card::HEART, 1});
  EXPECT_EQ(player.getScore(), 19);
}

TEST(BJPlayerTest, AceIs11) {
  BJPlayer player;

  player.takeCard(Card{Card::HEART, 8});
  player.takeCard(Card{Card::HEART, 1});
  EXPECT_EQ(player.getScore(), 19);
}
