#include "BJPlayer.hpp"
#include "BlackJackValue.hpp"

#include <iostream>
#include <iterator>

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

    constexpr int assBenefit{9};
    while (assNumber > 0 and handValue + assBenefit <= BlackJackValue) {
        handValue += assBenefit;
        assNumber--;
    }

    return handValue;
}

void BJPlayer::takeCard(Card newCard)
{
    hand.push_back(newCard);
}

void BJPlayer::printHand()
{
    std::cout << hand.front().getName();

    for (auto it = std::next(hand.begin()); it < hand.end(); it++) { // TODO make print from hand object
        std::cout << ", " << it->getName();
    }
}

void BJPlayer::resetHand()
{
    hand.clear();
}
