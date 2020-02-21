#pragma once

#include "Deck.hpp"

class DeckGenerator
{
public:
    virtual Deck getDeck() const = 0;
    virtual ~DeckGenerator() = default;
};
