// Idea: <ToDo> Describe the idea of multiple_inheritance 
//

#include <iostream>

class A
{
public:
    virtual void foo(int a){std::cout << "A" << std::endl; return 0;}
};

class B
{
public:
  virtual void foo(int a){ std::cout << "B" << std::endl; return true;}
};

class AdapterA : A
{
public:
void fooA(int a) { foo(); }
}

class AdapterB : B
{
public:
void fooB(int a) { foo(); }
}

class Child : AdapterA, AdapterB
{

  public:
//    bool foo(int a){ std::cout << "Child" << std::endl; return true;}
// The methods of A and B have the same signature but I want to override or use each individually
// With a minimized vtable

};

int main()
{
  Child c;
  bool a = c.foo(5);
}
