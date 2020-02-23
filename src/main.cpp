#include <iostream>

#include "CautionPlayer.hpp"
#include "CustomPlayer.hpp"
#include "ClassicCroupier.hpp"
#include "FileDeckGenerator.hpp"
#include "Game.hpp"

int main()
{
    std::cout << "BlackJack" << std::endl;

    auto customPlayer{std::make_unique<CustomPlayer>()};
    auto cautionPlayer{std::make_unique<CautionPlayer>()};
    auto classicCroupier{std::make_unique<ClassicCroupier>()};
    auto classicCroupier2{std::make_unique<ClassicCroupier>()};
    FileDeckGenerator deckGenerator{std::ifstream{"test/exampleDecks/exampleDeck.txt"}};

    Game game{std::move(cautionPlayer), std::move(classicCroupier), deckGenerator.getDeck()}; // TODO check if it's rvalue
    Game game2{std::move(customPlayer), std::move(classicCroupier2), deckGenerator.getDeck()};

    game.play();
    game2.play();
}
