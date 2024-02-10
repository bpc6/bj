#include "bj_player.h"

#include "card.h"
#include "gtest/gtest.h"

/**
 * BJNHitPlayer hits N times then stays.
 */
class BJNHitPlayer : public BJPlayer {
  int maxHits;
  int numHits = 0;

 public:
  BJNHitPlayer(const std::string& usr, int cash, int maxHits)
      : BJPlayer(usr, cash), maxHits(maxHits) {}
  void placeBet() override { bet = 2; }
  bool hit() override { return numHits++ < maxHits; }
};

TEST(BJPlayerTest, BasicScore) {
  BJNHitPlayer player{"3 hits", 10, 3};
  EXPECT_EQ(player.getScore(), 0);

  player.takeCard(Card{Card::HEART, 4});
  EXPECT_EQ(player.getScore(), 4);
}

TEST(BJPlayerTest, FaceCard) {
  BJNHitPlayer player{"3 hits", 10, 3};

  player.takeCard(Card{Card::HEART, 12});
  EXPECT_EQ(player.getScore(), 10);
}

TEST(BJPlayerTest, AceIs1) {
  BJNHitPlayer player{"3 hits", 10, 3};

  player.takeCard(Card{Card::HEART, 12});
  player.takeCard(Card{Card::HEART, 8});
  player.takeCard(Card{Card::HEART, 1});
  EXPECT_EQ(player.getScore(), 19);
}

TEST(BJPlayerTest, AceIs11) {
  BJNHitPlayer player{"3 hits", 10, 3};

  player.takeCard(Card{Card::HEART, 8});
  player.takeCard(Card{Card::HEART, 1});
  EXPECT_EQ(player.getScore(), 19);
}

TEST(BJPlayerTest, LoseBet) {
  BJNHitPlayer player{"3 hits", 10, 3};
  player.placeBet();
  EXPECT_EQ(player.payout(-1), 2);  // careful player always bets 2
  EXPECT_EQ(player.cashOnHand(), 8);
}

TEST(BJPlayerTest, WinBet) {
  BJNHitPlayer player{"3 hits", 10, 3};
  player.placeBet();
  EXPECT_EQ(player.payout(1), -2);
  EXPECT_EQ(player.cashOnHand(), 12);
}

TEST(BJPlayerTest, WinOnBJ) {
  BJNHitPlayer player{"3 hits", 10, 3};
  player.placeBet();
  EXPECT_EQ(player.payout(1.5), -3);  // 1.5 * player's bet of 2
  EXPECT_EQ(player.cashOnHand(), 13);
}

TEST(BJPlayerTest, PlayRoundDontBust) {
  BJNHitPlayer player{"3 hits", 10, 3};
  // 2 of Hearts will not be used because player hits 3x and 2H is at the bottom of the deck
  Deck noBust = {Card{Card::HEART, 2}, Card{Card::SPADE, 4}, Card{Card::CLUB, 3},
                 Card{Card::CLUB, 2},  Card{Card::SPADE, 1}, Card{Card::SPADE, 3}};

  int playerScore = player.playRound(noBust);
  EXPECT_EQ(playerScore, 13);
}

TEST(BJPlayerTest, PlayRoundAndBust) {
  BJNHitPlayer player{"3 hits", 10, 3};
  // 2 of Hearts will not be used because player hits 3x and 2H is at the bottom of the deck
  Deck noBust = {Card{Card::HEART, 2}, Card{Card::SPADE, 4}, Card{Card::CLUB, 3},
                 Card{Card::CLUB, 12}, Card{Card::SPADE, 2}, Card{Card::SPADE, 13}};

  int playerScore = player.playRound(noBust);
  EXPECT_EQ(playerScore, 0);
}
