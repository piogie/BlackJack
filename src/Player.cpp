#include "Player.hpp"

void Player::setCroupierCardValue(const Card& croupierCard)
{
    croupierCardValue = croupierCard.getValue(); // BUG It returns bad value if croupier has Ass
}
