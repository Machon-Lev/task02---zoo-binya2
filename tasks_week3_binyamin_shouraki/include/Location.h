#pragma once
#include <iostream>
struct Location{
    int x;
    int y;

    void setLocation(int _x, int _y) {
        x = _x;
        y = _y;
    }

    /*void setLocation(Location location) {
        setLocation(location.getX(), location.getY());
    }*/

    void setX(int _x)  {
        Location::x = _x;
    }

    void setY(int _y) {
        Location::y = _y;
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    Location& operator=(Location location ) {
        setLocation(location.getX(),location.getY());
        return *this;
    }

    Location& operator+=(Location location ){
        this->x += location.x;
        this->y += location.y;
        return *this;
    }

    bool operator==(Location location ) const{
        if (this->x == location.x and this->y == location.y)
            return true;
        return false;
    }

    bool operator!=(Location location ) const{
        if (*this == location)
            return false;
        return true;
    }

    friend std::ostream &operator<<(std::ostream &os, const Location &location) {
        os << "x: " << location.getX() << " y: " << location.getY();
        return os;
    }
};


