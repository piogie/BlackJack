#pragma once

#include "DeckGenerator.hpp"
#include "Deck.hpp"

#include <string>

class StringDeckGenerator : public DeckGenerator
{
public:
    explicit StringDeckGenerator(std::string unparsedDeck);
    virtual ~StringDeckGenerator() = default;

    Deck getDeck() const override;

private:
    Deck deck;

    void generateDeck(std::string unparsedDeck);
};
