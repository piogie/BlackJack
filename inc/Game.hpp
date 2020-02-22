#pragma once

#include "Croupier.hpp"
#include "Deck.hpp"
#include "Player.hpp"

enum class RoundStatus
{
    NoCards,
    PlayerWinner,
    CroupierWinner
};

class Game
{
public:
    Game(Player& player_, Croupier& croupier_, Deck deck_); // TODO check what if not const &

    void play();

private:
    RoundStatus playRound();

    Player& player;
    Croupier& croupier;
    Deck deck;
};
