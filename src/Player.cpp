#include "Player.hpp"

void Player::setCropierCardValue(const Card& croupierCard)
{
    croupierCardValue = croupierCard.getValue(); // BUG It returns bad value if croupier has Ass
}
