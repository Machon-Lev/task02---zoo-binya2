#pragma once
#include "Animal.h"
#include <ctime>
#include <cstdlib>
#define ROWS 20
#define COLS 40

class Dog : public Animal{
    bool turn = false;
    int direction = 0;
    int steps;
public:
    char getInitial() const override;

    Dog(const std::string &name, const Location &location);

    void turnDirection();

    void turnVertically() override;

    void turnHorizontally() override;

    void step() override;

    void printDetails() override;

    void move() override;

};


