#include "Game.hpp"

#include "BlackJackValue.hpp"

#include <iostream> // TODO Check ostream
#include <string>
#include <utility>

Game::Game(std::unique_ptr<Player> player_, std::unique_ptr<Croupier> croupier_, Deck deck_) :
    player{std::move(player_)},
    croupier{std::move(croupier_)},
    deck{deck_},
    playerScore{},
    croupierScore{}
{}

void Game::play()
{
    printStartGameNotification();

    while (isEnoughCardsToPlayRound()) {
        prepareForRound();
        auto roundWinner = playRound();
        printEndRoundNotification(roundWinner);
    }

    printEndGameNotification();
}

RoundWinner Game::playRound()
{
    player->takeCard(deck.back()); deck.pop_back(); // TODO refactor
    croupier->takeCard(deck.back()); deck.pop_back();
    player->takeCard(deck.back()); deck.pop_back();

    auto croupierCoveredCard = deck.back(); deck.pop_back();

    player->setCroupierCardValue(croupier->calculateHandValue());

    while (not deck.empty() and player->isHiting()) {
        auto card = deck.back();
        deck.pop_back();

        player->takeCard(card);
    }

    if (croupier->isHiting()) {
        croupier->takeCard(croupierCoveredCard);
    }
    while (not deck.empty() and croupier->isHiting()) {
        auto card = deck.back();
        deck.pop_back();
        croupier->takeCard(card);
    }

    return findWinner();
}

void Game::prepareForRound()
{
    player->resetHand();
    croupier->resetHand();
}

RoundWinner Game::findWinner()
{
    if (isPlayerWinner()) {
        playerScore++;
        return RoundWinner::PlayerWinner;
    }

    croupierScore++;
    return RoundWinner::CroupierWinner;
}

bool Game::isEnoughCardsToPlayRound()
{
    return deck.size() >= 4; // TODO remove magic number
}

bool Game::isPlayerWinner()
{
    auto playerHandValue = player->calculateHandValue();
    auto croupierHandValue = croupier->calculateHandValue();

    return
        isBusted(croupierHandValue) and not isBusted(playerHandValue)
        or
        not isBusted(playerHandValue) and not isBusted(croupierHandValue)
        and
        playerHandValue > croupierHandValue;
}

bool Game::isBusted(int handValue)
{
    return handValue > BlackJackValue;
}

void Game::printStartGameNotification()
{
    std::cout << "[Game started with player: " << player->getName() << "]" << std::endl;
}

void Game::printEndRoundNotification(RoundWinner endRoundWinner)
{
    std::cout << "Player: ";
    player->printHand();
    std::cout << ": " << player->calculateHandValue();

    std::cout << std::endl;

    std::cout << "Croupier: ";
    croupier->printHand();
    std::cout << ": " << croupier->calculateHandValue();

    std::cout << std::endl;

    std::string winner;
    if (endRoundWinner == RoundWinner::PlayerWinner) {
        winner = "Player";
    }
    else if (endRoundWinner == RoundWinner::CroupierWinner) {
        winner = "Croupier";
    }
    else {
        winner = "ERROR"; // TODO
    }

    std::cout
        << "[End round: " << winner << " wins"
        << " (" << playerScore << " : " << croupierScore << ")]";

    std::cout << std::endl;
}

void Game::printEndGameNotification()
{
    std::cout << "[End Game]" << std::endl;
}
