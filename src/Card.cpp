#include "Card.hpp"

Card::Card(std::string name_) :
    name{name_}
{}

std::string Card::getName() const
{
    return name;
}

int Card::getValue() const
{
    if (isNameNotNumber()) {
        if (isAss()) {
            return 1;
        }
        else {
            return 10;
        }
    }

    return std::stoi(name);
}

bool Card::isAss() const
{
    return name == "A";
}

bool Card::operator==(const Card& card) const
{
    return name == card.getName();
}

bool Card::isNameNotNumber() const
{
    return (name == "J" or name == "Q" or name == "K" or name == "A");
}
