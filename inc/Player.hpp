#pragma once

#include "BJPlayer.hpp"
#include "Card.hpp"

class Player : public BJPlayer
{
public:
    void setCropierCardValue(const Card&);

private:
    int croupierCardValue;
};
