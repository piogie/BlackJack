#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Card.hpp"

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
