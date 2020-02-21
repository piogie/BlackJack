#pragma once

#include "DeckGenerator.hpp"
#include "Deck.hpp"

#include <fstream>
#include <string>

class FileDeckGenerator : public DeckGenerator
{
public:
    explicit FileDeckGenerator(std::ifstream unparsedDeckFile);
    virtual ~FileDeckGenerator() = default;

    Deck getDeck() const override;

private:
    Deck deck;

    void generateDeck(std::ifstream& unparsedDeckFile);
};
