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
  EXPECT_EQ(deck.pop().getValue(), 13);
  EXPECT_EQ(deck.pop().getValue(), 4);
  EXPECT_EQ(deck.size(), 0);
}

TEST(DeckTest, NewDeckTopCard) {
  Deck deck;
  Card topcard = deck.peek();

  EXPECT_EQ(topcard.getValue(), 1);
  EXPECT_EQ(topcard.getSuit(), Card::Suit::HEART);
}

TEST(DeckTest, NewDeckTop13Cards) {
  Deck deck;

  for (int i = 0; i < 13; i++) {
    Card top = deck.pop();
    EXPECT_EQ(top.getValue(), i + 1);
    EXPECT_EQ(top.getSuit(), Card::Suit::HEART);
  }
}

TEST(DeckTest, NewDeckBottomCard) {
  Deck deck;

  for (int i = 0; i < 51; i++) {
    deck.pop();
  }
  Card last = deck.pop();
  EXPECT_EQ(last.getValue(), 1);
  EXPECT_EQ(last.getSuit(), Card::Suit::SPADE);
}

TEST(DeckTest, PopTooMany) {
  Deck deck({});
  EXPECT_EQ(deck.size(), 0);

  ASSERT_THROW(deck.pop(), std::out_of_range);
  ASSERT_THROW(deck.peek(), std::out_of_range);
}

TEST(DeckTest, Shuffle) {
  Deck deck;
  EXPECT_EQ(deck.peek().getValue(), 1);

  deck.shuffle();
  EXPECT_NE(deck.peek().getValue(), 1);
}

TEST(DeckTest, Push) {
  Deck deck{Card{Card::DIAMOND, 4}};
  deck.push(Card{Card::SPADE, 12});

  EXPECT_EQ(deck.peek().getValue(), 12);
  EXPECT_EQ(deck.size(), 2);
}

TEST(DeckTest, CombineDecks) {
  Deck deck1{Card{Card::DIAMOND, 4}};
  Deck deck2{Card{Card::SPADE, 12}, Card{Card::DIAMOND, 11}};

  Deck combined = deck1 + deck2;
  EXPECT_EQ(combined.pop().getValue(), 11);
  EXPECT_EQ(combined.pop().getValue(), 12);
  EXPECT_EQ(combined.pop().getValue(), 4);
  EXPECT_EQ(combined.size(), 0);
}

TEST(DeckTest, CombineNewDecks) { EXPECT_EQ((Deck() + Deck()).size(), 52 + 52); }
