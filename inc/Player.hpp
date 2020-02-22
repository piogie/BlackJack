#pragma once

#include "BJPlayer.hpp"
#include "Card.hpp"

#include <string>

class Player : public BJPlayer
{
public:
    void setCropierCardValue(const Card&);
    virtual std::string getName() = 0;

private:
    int croupierCardValue;
};
