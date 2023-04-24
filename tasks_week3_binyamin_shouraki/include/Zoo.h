#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <memory>
#include "Animal.h"
#include "Lion.h"
#include "Monkey.h"
#include "Dog.h"

#define ROWS 20
#define COLS 40

class Zoo {
    std::vector<std::unique_ptr<Animal>> animals;
    void stop(int);
    void move(int);
    void create(char, std::string);
    void del(int);
    void delAll(char);
    void help();
    void step();
    void print_map();
    void print_list();
public:
	void run();
};



