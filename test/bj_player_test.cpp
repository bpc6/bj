#include "bj_player.h"

#include "card.h"
#include "gtest/gtest.h"

/**
 * Concrete BJPlayer just for testing. Careful player always bets 1 and never hits.
 */
class BJCarefulPlayer : public BJPlayer {
 public:
  BJCarefulPlayer(const std::string& usr, int cash) : BJPlayer(usr, cash) {}
  void placeBet() override { bet = 1; }
  bool hit() override { return false; }
};

TEST(BJPlayerTest, BasicScore) {
  BJCarefulPlayer player{"usr", 10};
  EXPECT_EQ(player.getScore(), 0);

  player.takeCard(Card{Card::HEART, 4});
  EXPECT_EQ(player.getScore(), 4);
}

TEST(BJPlayerTest, FaceCard) {
  BJCarefulPlayer player{"usr", 10};

  player.takeCard(Card{Card::HEART, 12});
  EXPECT_EQ(player.getScore(), 10);
}

TEST(BJPlayerTest, AceIs1) {
  BJCarefulPlayer player{"usr", 10};

  player.takeCard(Card{Card::HEART, 12});
  player.takeCard(Card{Card::HEART, 8});
  player.takeCard(Card{Card::HEART, 1});
  EXPECT_EQ(player.getScore(), 19);
}

TEST(BJPlayerTest, AceIs11) {
  BJCarefulPlayer player{"usr", 10};

  player.takeCard(Card{Card::HEART, 8});
  player.takeCard(Card{Card::HEART, 1});
  EXPECT_EQ(player.getScore(), 19);
}

TEST(BJPlayerTest, LoseBetAfterBust) {
  BJCarefulPlayer player{"usr", 10};
  player.placeBet();
  EXPECT_EQ(player.loseBet(), 1);  // careful player always bets 1
  EXPECT_EQ(player.cashOnHand(), 9);
}
