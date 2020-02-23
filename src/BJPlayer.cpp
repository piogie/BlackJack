#include "BJPlayer.hpp"
#include "BlackJackValue.hpp"

#include <iostream>
#include <iterator>

void BJPlayer::takeCard(Card newCard)
{
    hand.push_back(newCard);
}

int BJPlayer::calculateHandValue() const
{
    int handValue{};
    int assNumber{};

    for (const auto& card : hand) {
        if (card.isAss()) {
            assNumber++;
        }

        handValue += card.getValue();
    }

    constexpr int assBenefit{9}; // TODO move assBenefit outside
    while (assNumber > 0 and handValue + assBenefit <= BlackJackValue) {
        handValue += assBenefit;
        assNumber--;
    }

    return handValue;
}

void BJPlayer::printHand() const
{
    std::cout << hand.front().getName();

    for (auto it = std::next(hand.cbegin()); it < hand.cend(); it++) {
        std::cout << ", " << it->getName();
    }
}

void BJPlayer::resetHand()
{
    hand.clear();
}
