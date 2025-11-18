#include <stdio.h>
#include <iostream>
#include "vector/vector.h"

struct Human
{
    unsigned int age;
    const char* name;

    void Display()
    {
        std::cout << "age of " << name << " is " << age << std::endl;
    }
};


int main()
{
    PulseLibs::STL::Vector<Human*> humanList;
    unsigned long int totalSize = 0;
    humanList.Pushback(new Human{.age = 10, .name = "Louis"});
    humanList.Pushback(new Human{.age = 15, .name = "Maxime"});
    humanList.Pushback(new Human{.age = 20, .name = "James"});
    humanList.Pushback(new Human{.age = 17, .name = "Pierre"});

    for(auto hmIt = humanList.Begin(); hmIt != humanList.End(); ++hmIt )
    {
        Human* hm = *hmIt;
        hm->Display();
    }

    std::cout << "end of program..." << std::endl;
    std::cin.get();
    return 0;
}