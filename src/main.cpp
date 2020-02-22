#include <iostream>

#include "CautionPlayer.hpp"
#include "ClassicCroupier.hpp"
#include "FileDeckGenerator.hpp"
#include "Game.hpp"

int main()
{
    std::cout << "BlackJack" << std::endl;

    CautionPlayer cautionPlayer;
    ClassicCroupier classicCroupier;
    FileDeckGenerator deckGenerator{std::ifstream{"test/exampleDecks/exampleDeck.txt"}};
    Game game{cautionPlayer, classicCroupier, deckGenerator.getDeck()}; // TODO check if it's rvalue

    game.play();
}
