#pragma once

#include "Croupier.hpp"

class ClassicCroupier : public Croupier
{
public:
    bool isHiting() const override;
};
