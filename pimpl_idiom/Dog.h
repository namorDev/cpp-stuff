#pragma once

#include <memory>

class Dog
{

    class DogImpl;

public:
    Dog();
    ~Dog();

    void eat();
    void shit();

private:

    std::unique_ptr<DogImpl> m_impl;
};
