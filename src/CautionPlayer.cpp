#include "CautionPlayer.hpp"

bool CautionPlayer::isHiting()
{
    if (calculateHandValue() >= 12) {
        return true;
    }

    return false;
}