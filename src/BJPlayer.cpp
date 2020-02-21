#include "BJPlayer.hpp"
#include "BlackJackValue.hpp"

int BJPlayer::calculateHandValue() const
{
    int handValue{};
    int assNumber{};

    for (const auto& card : hand) {
        if (card.isItAss()) {
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
