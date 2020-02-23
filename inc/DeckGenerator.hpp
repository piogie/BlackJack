#pragma once

#include "Deck.hpp"

class DeckGenerator
{
public:
    virtual ~DeckGenerator() = default;

    virtual Deck getDeck() const = 0;
};
