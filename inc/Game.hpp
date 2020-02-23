#pragma once

#include "Croupier.hpp"
#include "Deck.hpp"
#include "Player.hpp"

#include <memory>

enum class RoundWinner
{
    PlayerWinner,
    CroupierWinner
};

class Game
{
public:
    Game(std::unique_ptr<Player> player_, std::unique_ptr<Croupier> croupier_, Deck deck_); // TODO check what if const &

    void play();

private:
    void prepareForRound();
    RoundWinner playRound();

    bool isEnoughCardsToPlayRound();

    void printStartGameNotification();
    void printEndRoundNotification(RoundWinner endRoundWinner);
    void printEndGameNotification();

    bool isBusted(int handValue);
    bool isPlayerWinner();


    RoundWinner findWinner();

    std::unique_ptr<Player> player;
    std::unique_ptr<Croupier> croupier;
    Deck deck;

    int playerScore;
    int croupierScore;
};
