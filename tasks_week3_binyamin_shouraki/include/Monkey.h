#pragma once
#include "Animal.h"
#include <ctime>
#include <cstdlib>


class Monkey : public Animal{
    int direction = left;
    int turn = 4;
    int steps;
public:
    Monkey(const std::string &name, const Location &location);

    char getInitial() const override;

    void turnVertically() override;

    void turnHorizontally() override;

    void printDetails() override;

    void step() override;
};


