#pragma once

#include "Player.hpp"

#include <string>

class CustomPlayer : public Player
{
public:
    std::string getName() override;
    bool isHiting() override;
};
