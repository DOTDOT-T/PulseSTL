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
    for(unsigned int i = 0; i < 150; ++i)
    {
        humanList.Pushback({.age = i, .name = "Human structured"});
        totalSize += sizeof(Human);
    }
    for(unsigned int i = 0; i < 150; ++i)
    {
        std::cout << "Age at index " << i << " : " << humanList[i].age << " and name : " << humanList[i].name << std::endl;
    }

    std::cout << "size of humanList (content) \t\t: " << totalSize << std::endl;
    std::cout << "size of humanList (variable) \t: " << sizeof(humanList) << std::endl;
    
    std::cin.get();
    return 0;
}