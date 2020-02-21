#include "StringDeckGenerator.hpp"

StringDeckGenerator::StringDeckGenerator(std::string unparsedDeck)
{
    generateDeck(unparsedDeck);
}

Deck StringDeckGenerator::getDeck() const
{
    return deck;
}

void StringDeckGenerator::generateDeck(std::string unparsedDeck)
{
    constexpr auto delimeter = ';';
    std::string card{};

    for (auto character : unparsedDeck) {
        if (character != delimeter) {
            card += character;
        }
        else {
            deck.emplace_back(card);
            card.clear();
        }
    }
}
