// Idea: <ToDo> Describe the idea of multiple_inheritance 
//

#include <iostream>

class A
{
public:
    int foo(int a){std::cout << "A" << std::endl; return 0;}
};

class B
{
public:
  bool foo(int a){ std::cout << "B" << std::endl; return true;}
};


class Child : A,B
{

  public:
//    bool foo(int a){ std::cout << "Child" << std::endl; return true;}
};

int main()
{
  Child c;
  bool a = c.foo(5);
}
