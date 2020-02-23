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
    void printHand() const; // TODO make print from hand member
    void resetHand();

private:
    std::vector<Card> hand;
};
