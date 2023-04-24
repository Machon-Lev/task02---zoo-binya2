//
// Created by binya on 23/04/2023.
//

#include "Lion.h"


void Lion::turnVertically() { }

void Lion::turnHorizontally() {
    if (direction)
        direction = left;
    else
        direction = right;
}

void Lion::step() {
    Location loc = getLocation();
    if (direction == left) {
        if (loc.getY() > 2) {
            loc.setY(loc.getY() - 2);
            setLocation(loc);
        }
        else if (loc.getY() == 2){
            loc.setY(0);
            setLocation(loc);
            direction = right;
        }else
            direction = right;
    }else{
        if (loc.getY() < COLS - 3) {
            loc.setY(loc.getY() + 2);
            setLocation(loc);
        }
 
        else if (loc.getY() == COLS - 3){
            loc.setY(COLS - 1);
            setLocation(loc);
            direction = left;
        }else
            direction = left;
    }
}

char Lion::getInitial() const {
    return 'L';
}



void Lion::printDetails() {
    std::cout <<  "type: Lion, name: " << getName()  << " location: " << getLocation() << std::endl;
}

Lion::Lion(const std::string &name, const Location &location) : Animal(name, location) {}



