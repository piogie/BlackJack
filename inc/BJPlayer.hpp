#pragma once

#include "Card.hpp"

#include <vector>

class BJPlayer
{
public:
    virtual ~BJPlayer() = default;

    virtual bool isHiting() = 0;
    void takeCard(Card newCard);
    int calculateHandValue() const;

    void printHand(); // TMP probably
    void resetHand();

private:
    std::vector<Card> hand;
};
