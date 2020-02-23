#pragma once

#include "BJPlayer.hpp"
#include "Card.hpp"

#include <string>

class Player : public BJPlayer
{
public:
    virtual ~Player() = default;

    void setCropierCardValue(const Card&);
    virtual std::string getName() const = 0;

private:
    int croupierCardValue;
};
