#include "deck.h"

#include "gtest/gtest.h"

TEST(DeckConstructorTest, NewDeckTopCard) {
  Deck deck;
  Card topcard = deck.peek();

  EXPECT_EQ(topcard.value, 1);
  EXPECT_EQ(topcard.suit, Card::Suit::HEART);
}
