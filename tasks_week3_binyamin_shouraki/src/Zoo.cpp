#include "Zoo.h"

void Zoo::stop(int index) {
    animals[index]->stop();
}

void Zoo::move(int index) {
    animals[index]->move();
}

void Zoo::step() {
    for (int i = 0; i < animals.size(); ++i) {
        animals[i]->step();
    }
}

void Zoo::print_list() {
    std::cout << "List of Animal in the Zoo:\n";
    for (int i = 0; i < animals.size(); ++i) {
        std::cout << i << ": ";
        animals[i]->printDetails();
    }
}

void Zoo::create(char type, std::string name) {
    int row = rand() % ROWS;
    int col = rand() % COLS;
    switch (type) {
        case 'L':
            animals.push_back(std::make_unique<Lion>(name, Location(row, col)));
            break;
        case 'M':
            animals.push_back(std::make_unique<Monkey>(name, Location(row, col)));
            break;
        case 'D':
            animals.push_back(std::make_unique<Dog>(name, Location(row, col)));
            break;
        default:
            std::cout << "Invalid operation";
            break;
    }
}

void Zoo::del(int index) {
    animals.erase(animals.begin()+ index);
}

void Zoo::delAll(char type) {
    for (int i = 0; i < animals.size(); ++i) {
        if (animals[i]->getInitial() == type) {
            del(i);
            i--;
        }
    }
}

void Zoo::print_map() {
    std::cout << "map:" << std::endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            bool is_valid = true;
            for (std::unique_ptr<Animal>& t : animals) {
                if (t->getLocation() == Location(i, j)) {
                    if (is_valid)
                        std::cout << t->getInitial();
                    is_valid = false;
                }
            }
            if (is_valid)
                std::cout << "-";
        }
        std::cout << "\n";
    }
}

void Zoo::help() {
    std::cout << "Enter 'help' for a list of commands.\n"

    << "Enter '.' to step all the animals\n"

    << "Enter 'stop' to stop animal\n"

    << "Enter 'move' to move animal\n"

    << "Enter 'create' to create a new animal\n"

    << "Enter 'del' to delete animal\n"

    << "Enter 'delAll' to delete all animals from one type\n"

    << "Enter 'exit' to exit\n";
}

void Zoo::run() {
    std::string command;
    int index;
    char type;
    std::string name;

    print_list();
    print_map();
    help();
    std::cin >> command;
    while (command != "exit") {
        if (command == ".") {
            step();
        }
        else if( "stop" == command) {
            std::cout << "enter index of animal: \n";
            std::cin >> index;
            if (index >= animals.size())
                std::cout << "Index out of range!";
            else {
                stop(index);
                step();
            }
        }
        else if( "move" == command) {
            std::cout << "enter index of animal: \n";
            std::cin >> index;
            if (index >= animals.size())
                std::cout << "Index out of range!";
            else {
                move(index);
                step();
            }
        }
        else if( "create" == command) {
            std::cout << "enter L for Lion M for Monkey and D for Dog: \n";
            std::cin >> type;
            if (type == 'M' || type == 'L' || type == 'D') {
                std::cout << "enter the name of the animal\n";
                std::cin >> name;
                create(type, name);
                step();
            } else
                std::cout << "invalid input";
        }
        else if( "del" == command) {
            std::cout << "enter index of animal to delete\n";
            std::cin >> index;
            if (index >= animals.size())
                std::cout << "Index out of range!";
            else {
                del(index);
                step();
            }
        }
        else if( "delAll" == command) {
            std::cout << "enter L for Lion M for Monkey and D for Dog\n";
            std::cin >> type;
            if (type != 'M' && type != 'L' && type != 'G')
                std::cout << "invalid input";
            else {
                delAll(type);
                step();
            }
        }
        else if( "help" == command)
            help();
        else
            std::cout << "Invalid case" << std::endl;
        print_list();
        print_map();
        std::cin >> command;
    }
}
