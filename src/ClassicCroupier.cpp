#include "ClassicCroupier.hpp"

bool ClassicCroupier::isHiting() const
{
    if (calculateHandValue() <= 17) {
        return true;
    }

    return false;
}
