#include "ClassicCroupier.hpp"

bool ClassicCroupier::isHiting()
{
    if (calculateHandValue() <= 17) {
        return true;
    }

    return false;
}
