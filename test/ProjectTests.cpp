#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CautionPlayer.hpp"
#include "Card.hpp"
#include "ClassicCroupier.hpp"
#include "Deck.hpp"
#include "FileDeckGenerator.hpp"
#include "Game.hpp"
#include "StringDeckGenerator.hpp"


#include <fstream>
#include <string>
#include <vector>

SCENARIO("Card", "[Card]") {
    GIVEN("Card, one ass") {
        Card ass{"A"};

        WHEN("getValue() is called") {
            auto result = ass.getValue();

            THEN("The result is 1") {
                CHECK(result == 1);
            }
        }
    }

    GIVEN("Cards: one jack, one queen, one king") {
        std::vector<Card> cards{Card{"J"}, Card{"Q"}, Card{"K"}};

        WHEN("getValue() is called") {
            int result{};
            for (const auto& card : cards) {
                result += card.getValue();
            }

            THEN("The result is 30") {
                CHECK(result == 30);
            }
        }
    }

    GIVEN("Cards: one three, one four, one seven") {
        std::vector<Card> cards{Card{"3"}, Card{"4"}, Card{"7"}};

        WHEN("getValue() is called") {
            int result{};
            for (const auto& card : cards) {
                result += card.getValue();
            }

            THEN("The result is 14") {
                CHECK(result == 14);
            }
        }
    }
}

SCENARIO("StringDeckGenerator", "[StringDeckGenerator]") {
    GIVEN("StringDeckGenerator, '3;10;J;A' input string") {
        const std::string input{"3;10;J;A;"};
        StringDeckGenerator deckGenerator{input};

        WHEN("getDeck() is called") {
            auto result = deckGenerator.getDeck();

            THEN("The result is Deck{3, 10, J, A}") {
                CHECK(result == Deck{Card{"3"}, Card{"10"}, Card{"J"}, Card{"A"}});
            }
        }
    }
}

SCENARIO("FileDeckGenerator", "[FileDeckGenerator]") {
    GIVEN("FileDeckGenerator, '3;10;J;A' from exampleDeck2.txt") {
        FileDeckGenerator deckGenerator{std::ifstream{"test/exampleDecks/exampleDeck2.txt"}};

        WHEN("getDeck() is called") {
            auto result = deckGenerator.getDeck();

            THEN("The result is Deck{3, 10, J, A}") {
                CHECK(result == Deck{Card{"3"}, Card{"10"}, Card{"J"}, Card{"A"}});
            }
        }
    }
}

SCENARIO("Game", "[Game]") {
    GIVEN("Game with Caution Player and Classic Croupier") {
        auto cautionPlayer{std::make_unique<CautionPlayer>()}; // TODO check if auto and what with {}
        auto classicCroupier{std::make_unique<ClassicCroupier>()};
        StringDeckGenerator deckGenerator{
            "8;A;5;8;9;J;2;Q;Q;J;4;K;10;6;6;A;10;9;2;K;K;10;6;7;3;5;2;4;4;7;3;3;A;7;8;K;2;J;7;8;J;9;4;5;10;5;Q;3;9;6;A;Q;"
        };

        Game game{std::move(cautionPlayer), std::move(classicCroupier), deckGenerator.getDeck()}; // TODO check if it's rvalue or by new

        WHEN("play() is called") {
            game.play();
            auto result = true;

            THEN("The result is ???") {
                CHECK(result == true);
            }
        }
    }
}
