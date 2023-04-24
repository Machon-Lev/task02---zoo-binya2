#pragma once
#include <iostream>
#include <utility>
#include "Location.h"

#define right  1
#define left  0
#define up  2
#define down  3

class Animal{
    std::string name;
    Location location;
    bool is_move;
    int direction;

public:
   
    Animal(const std::string &name, const Location &location) : name(name),location(location),is_move(true) {}

    virtual char getInitial() const {
        return ' ';
    }
    virtual void printDetails() = 0;

    virtual void turnVertically() = 0;

    virtual void turnHorizontally() = 0;

    virtual void step() = 0;

    [[nodiscard]] const std::string &getName() const {
        return name;
    }

    virtual void move(){
        is_move = true;
    }

    virtual void stop(){
        is_move = false;
    }

    virtual const Location getLocation() {
        return location;
    }

    virtual void setLocation(const Location &_location) {
        Animal::location = _location;
    }

    virtual void setName(const std::string &_name) {
        Animal::name = _name;
    }

public:
    friend std::ostream &operator<<(std::ostream &os, const Animal &animal) {
        os << "name: " << animal.name << " location: " << animal.location;
        return os;
    }
};


