#pragma once

#include "BJPlayer.hpp"
#include "Card.hpp"

#include <string>

class Player : public BJPlayer
{
public:
    virtual ~Player() = default;

    virtual std::string getName() const = 0;

    void setCropierCardValue(const Card&);

private:
    int croupierCardValue;
};
