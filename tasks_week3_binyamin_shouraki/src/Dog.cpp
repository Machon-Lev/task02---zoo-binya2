//
// Created by binya on 23/04/2023.
//

#include "Dog.h"

char Dog::getInitial() const {
    return 'D';
}

void Dog::turnVertically() {
    if (direction == down)
        direction = up;
    else
        direction = down;
}

void Dog::turnHorizontally() {
    if (direction == left)
        direction = right;
    else
        direction = left;
}


void Dog::step() {
    Location loc = this->getLocation();
    if(turn == false){
        steps = 3;
        turn = true;
    }else{
        steps = -1;
        turn = false; 
    }

    switch (direction) {
        case left:
            if (loc.getY() - steps >= 0) {
                loc.setY(loc.getY() - steps);
                setLocation(loc);
            }
            else {
                loc.setY(loc.getY() + steps);
                setLocation(loc);
                turnHorizontally();
            }
            break;
        case right:
            if (loc.getY() + steps <= 39) {
                loc.setY(loc.getY() + steps);
                setLocation(loc);
            }
            else {
                loc.setY(loc.getY() - steps);
                setLocation(loc);
                turnHorizontally();
            }
            break;
        case up:
            if (loc.getX() - steps >= 0) {
                loc.setX(loc.getX() - steps);
                setLocation(loc);
            }
            else {
                loc.setX(loc.getX() + steps);
                setLocation(loc);
                turnVertically();
            }
            break;
        case down:
            if (loc.getX() + steps <= 19) {
                loc.setX(loc.getX() + steps);
                setLocation(loc);
            }
            else {
                loc.setX(loc.getX() - steps);
                setLocation(loc);
                turnVertically();
            }
            break;
    }
}

void Dog::move() {
    Animal::move();
    srand((unsigned)time(NULL));
    direction = static_cast<int>(rand() % 4);
}

void Dog::printDetails() {
    std::cout <<  "type: Dog, name: " << getName()  << " location: " << getLocation() << std::endl;
}

Dog::Dog(const std::string &name, const Location &location) : Animal(name, location) {}

