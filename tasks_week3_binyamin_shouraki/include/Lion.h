#pragma once
#include "Animal.h"
#define ROWS 20
#define COLS 40


class Lion : public Animal {
    int direction;
public:
    Lion(const std::string &name, const Location &location);

    void turnVertically() override;

    void turnHorizontally() override;

    void printDetails() override;

    void step() override;

    char getInitial() const override;
};



