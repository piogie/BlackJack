#include "Game.hpp"

#include "BlackJackValue.hpp"

#include <iostream> // TODO Check ostream

Game::Game(Player& player_, Croupier& croupier_, Deck deck_) :
    player{player_},
    croupier{croupier_},
    deck{deck_}
{}

void Game::play()
{
    playRound();
}

RoundStatus Game::playRound()
{
    if (deck.size() < 4) {
        return RoundStatus::NoCards;
    }

    player.takeCard(deck.back()); deck.pop_back();
    croupier.takeCard(deck.back()); deck.pop_back();
    player.takeCard(deck.back()); deck.pop_back();

    auto croupierCoverCard = deck.back(); deck.pop_back();

    while (not deck.empty() and player.isHiting()) {
        auto card = deck.back();
        deck.pop_back();

        player.takeCard(card);
    }

    if (croupier.isHiting()) {
        croupier.takeCard(croupierCoverCard);
    }
    while (not deck.empty() and croupier.isHiting()) {
        auto card = deck.back();
        deck.pop_back();
        croupier.takeCard(card);
    }

    player.printHand();
    croupier.printHand();

    auto playerVal = player.calculateHandValue();
    auto croupierval = croupier.calculateHandValue();

    std::cout << "playerVal: " << playerVal << " crupierVal: " << croupierval << std::endl;

    if (playerVal <= BlackJackValue and playerVal > croupierval) {
        return RoundStatus::PlayerWinner;
    }
    else {
        return RoundStatus::CroupierWinner;
    }
}
