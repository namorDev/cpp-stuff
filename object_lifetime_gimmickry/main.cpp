#include <iostream>
#include <memory>

class RuleOfFive
{
public:
    // It does not make sense to have all ctors because there is no member to copy or move.
    // But this is just for the sake of completeness
    RuleOfFive() {std::cout << "Constructor" << std::endl;}
    RuleOfFive(const RuleOfFive &) {std::cout << "Copy Constructor" << std::endl;}
    RuleOfFive(RuleOfFive &&) noexcept {std::cout << "Move Constructor" << std::endl;}
    RuleOfFive& operator=(const RuleOfFive &) {std::cout << "Copy Assignment" << std::endl; return *this;}
    RuleOfFive& operator=(RuleOfFive &&) noexcept {std::cout << "Move Assignment" << std::endl; return *this;}
    ~RuleOfFive() noexcept {std::cout << "Destructor" << std::endl;}
};

void interfaceFunction(RuleOfFive* rawPointer)
{
    std::cout << "interfaceFunction called" << std::endl;
}

/////////////////////////////////////////////////////////////////////////
// A) Passing a unique_ptr to a function which takes a raw pointer
/////////////////////////////////////////////////////////////////////////
void uniquePtrToRawPointerFunction()
{
    std::unique_ptr<RuleOfFive> uniquePtr = std::make_unique<RuleOfFive>();

    // Use get() to get the raw pointer
    interfaceFunction(uniquePtr.get());

    std::cout << "End of test" << std::endl;

    // interfaceFunction should not use the ptr anymore, because uniquePtr gets destroyed here.
    // if you explicitly move the ownership to interfaceFunction, then it can do whatever it wants, but is responsible for
    // releasing the resource (delete)
}

int main() {

    uniquePtrToRawPointerFunction();
    
    return 0;
}
