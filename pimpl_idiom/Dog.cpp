#include "Dog.h"

#include <iostream>

class Dog::DogImpl
{
public:
    DogImpl(int vari) : aPrivateVariable(vari){};
    void eat()
    {
        std::cout << "Eat" << std::endl;
    }
    void shit()
    {
        std::cout << "Shit" << std::endl;
        std::cout << aPrivateVariable << std::endl;
    }

private:
    int aPrivateVariable;
};

Dog::Dog() : m_impl(new DogImpl{5}) {}

Dog::~Dog() {}

void Dog::eat()
{
    m_impl->eat();
}

void Dog::shit()
{
    m_impl->shit();
}
