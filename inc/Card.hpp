#pragma once

#include <string>

class Card
{
public:
    explicit Card(std::string name_);

    std::string getName() const;
    int getValue() const;
    bool isAss() const;

    bool operator==(const Card& card) const;

private:
    const std::string name;

    bool isNameNotNumber() const;
};
