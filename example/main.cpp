#include <stdio.h>
#include <iostream>
#include "vector/vector.h"

struct Human
{
    unsigned int age;
    const char* name;
};

int main()
{
    PulseLibs::STL::Vector<Human> humanList;
    unsigned long int totalSize = 0;
    Human* hm = humanList.Back();
    if(hm)
    {
        std::cout << "age of " << hm->name << " is " << hm->age << std::endl;
    }
    humanList.Pushback({.age = 10, .name = "Louis"});
    humanList.Pushback({.age = 15, .name = "Maxime"});

    
    std::cin.get();
    return 0;
}