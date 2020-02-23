#include "StringDeckGenerator.hpp"

#include <utility>

StringDeckGenerator::StringDeckGenerator(const std::string& unparsedDeck)
{
    generateDeck(unparsedDeck);
}

Deck StringDeckGenerator::getDeck() const
{
    return deck;
}

void StringDeckGenerator::generateDeck(const std::string& unparsedDeck)
{
    constexpr auto delimeter = ';';
    std::string card;

    for (auto cardPart : unparsedDeck) {
        if (cardPart != delimeter) {
            card += cardPart;
        }
        else {
            deck.emplace_back(card);
            card.clear();
        }
    }
}
