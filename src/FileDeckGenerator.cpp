#include "FileDeckGenerator.hpp"

FileDeckGenerator::FileDeckGenerator(std::ifstream unparsedDeckFile)
{
    generateDeck(unparsedDeckFile);
}

Deck FileDeckGenerator::getDeck() const
{
    return deck;
}

void FileDeckGenerator::generateDeck(std::ifstream& unparsedDeckFile)
{
    constexpr auto delimeter = ';';
    std::string card;

    if (unparsedDeckFile.is_open()) {
        while (std::getline(unparsedDeckFile >> std::ws, card, delimeter)) {
            deck.emplace_back(card);
        }

        unparsedDeckFile.close();
    }
}
