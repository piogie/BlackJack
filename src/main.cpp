#include <iostream>

#include "CautionPlayer.hpp"
#include "ClassicCroupier.hpp"
#include "FileDeckGenerator.hpp"
#include "Game.hpp"

int main()
{
    std::cout << "BlackJack" << std::endl;

    auto cautionPlayer{std::make_unique<CautionPlayer>()};
    auto classicCroupier{std::make_unique<ClassicCroupier>()};
    FileDeckGenerator deckGenerator{std::ifstream{"test/exampleDecks/exampleDeck.txt"}};

    Game game{std::move(cautionPlayer), std::move(classicCroupier), deckGenerator.getDeck()}; // TODO check if it's rvalue

    game.play();
}
