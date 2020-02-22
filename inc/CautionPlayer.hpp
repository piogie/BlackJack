#pragma once

#include "Player.hpp"

#include <string>

class CautionPlayer : public Player
{
public:
    std::string getName() override;
    bool isHiting() override;
};
