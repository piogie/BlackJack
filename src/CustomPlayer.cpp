#include "CustomPlayer.hpp"

bool CustomPlayer::isHiting()
{
    if (calculateHandValue() <= 15) {
        return true;
    }

    return false;
}

std::string CustomPlayer::getName() const
{
    return "custom player"; // TODO or mby return name
}
