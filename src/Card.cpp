#include "Card.hpp"

Card::Card(std::string name_) :
    name{name_}
{}

bool Card::isItAss() const
{
    return name == "A";
}

int Card::getValue() const
{
    if (isNameNotNumber()) {
        if (isItAss()) {
            return 1;
        }
        else {
            return 10;
        }
    }

    return std::stoi(name);
}

bool Card::isNameNotNumber() const
{
    return (name == "J" or name == "Q" or name == "K" or name == "A");
}
