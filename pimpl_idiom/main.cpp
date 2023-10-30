// Idea: <ToDo> Describe the idea of pimpl_idiom
// Acts as a compiler firewall
//
#include <iostream>

// ToDo: add class Dog inplace

#include "Dog.h"

int main()
{
    Dog d{};
    d.shit();
    std::cout << "hello" << std::endl;
}
