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
        CautionPlayer cautionPlayer;
        ClassicCroupier classicCroupier;
        FileDeckGenerator deckGenerator{std::ifstream{"test/exampleDecks/exampleDeck.txt"}};
        Game game{cautionPlayer, classicCroupier, deckGenerator.getDeck()}; // TODO check if it's rvalue or by new

        WHEN("play() is called") {
            game.play();
            auto result = true;

            THEN("The result is ???") {
                CHECK(result == true);
            }
        }
    }
}
