#pragma once

#include "Deck.hpp"
#include "DeckGenerator.hpp"

#include <fstream>

class FileDeckGenerator : public DeckGenerator
{
public:
    virtual ~FileDeckGenerator() = default;

    explicit FileDeckGenerator(std::ifstream unparsedDeckFile);

    Deck getDeck() const override;

private:
    Deck deck;

    void generateDeck(std::ifstream& unparsedDeckFile);
};
