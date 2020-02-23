#include "CautionPlayer.hpp"

bool CautionPlayer::isHiting()
{
    if (calculateHandValue() <= 12) {
        return true;
    }

    return false;
}

std::string CautionPlayer::getName() const
{
    return "caution player"; // TODO or mby return name
}
