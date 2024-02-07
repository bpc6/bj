#include "deck.h"

#include "gtest/gtest.h"

TEST(DeckTest, SizeCheck) {
  Deck deck;
  EXPECT_EQ(deck.size(), 52);

  deck.pop();
  EXPECT_EQ(deck.size(), 51);
}

TEST(DeckTest, InitList) {
  Deck deck{Card{Card::SPADE, 4}, Card{Card::HEART, 13}};
  EXPECT_EQ(deck.size(), 2);
  EXPECT_EQ(deck.pop().value, 13);
  EXPECT_EQ(deck.pop().value, 4);
  EXPECT_EQ(deck.size(), 0);
}

TEST(DeckTest, NewDeckTopCard) {
  Deck deck;
  Card topcard = deck.peek();

  EXPECT_EQ(topcard.value, 1);
  EXPECT_EQ(topcard.suit, Card::Suit::HEART);
}

TEST(DeckTest, NewDeckTop13Cards) {
  Deck deck;

  for (int i = 0; i < 13; i++) {
    Card top = deck.pop();
    EXPECT_EQ(top.value, i + 1);
    EXPECT_EQ(top.suit, Card::Suit::HEART);
  }
}

TEST(DeckTest, NewDeckBottomCard) {
  Deck deck;

  for (int i = 0; i < 51; i++) {
    deck.pop();
  }
  Card last = deck.pop();
  EXPECT_EQ(last.value, 1);
  EXPECT_EQ(last.suit, Card::Suit::SPADE);
}

TEST(DeckTest, PopTooMany) {
  Deck deck({});
  EXPECT_EQ(deck.size(), 0);

  ASSERT_THROW(deck.pop(), std::out_of_range);
  ASSERT_THROW(deck.peek(), std::out_of_range);
}
