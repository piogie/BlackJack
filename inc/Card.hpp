#pragma once

#include <string>

class Card
{
public:
    explicit Card(std::string name_);

    int getValue() const;

    std::string getName() const;
    bool operator==(const Card& card) const;
    bool isAss() const;

private:
    const std::string name;

    bool isNameNotNumber() const;
};
