#include "BJPlayer.hpp"

int BJPlayer::calculateHandValue() const
{
    int handValue{};

    for (const auto& card : hand) {
        handValue += card.getValue();
    }

    return handValue;
}

void BJPlayer::takeCard(Card newCard)
{
    hand.push_back(newCard);
}
