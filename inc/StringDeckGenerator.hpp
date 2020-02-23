#pragma once

#include "DeckGenerator.hpp"
#include "Deck.hpp"

#include <string>

class StringDeckGenerator : public DeckGenerator
{
public:
    virtual ~StringDeckGenerator() = default;

    explicit StringDeckGenerator(const std::string& unparsedDeck);

    Deck getDeck() const override;

private:
    Deck deck;

    void generateDeck(const std::string& unparsedDeck);
};
