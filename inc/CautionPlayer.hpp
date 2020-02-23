#pragma once

#include "Player.hpp"

#include <string>

class CautionPlayer : public Player
{
public:
    std::string getName() const override;
    bool isHiting() const override;
};
