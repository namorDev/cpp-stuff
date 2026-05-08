#include <iostream>
#include <string>
#include <string_view>

int main()
{
    ////////// Problem: s1 makes a copy of its initializer. 
    /// the literal "Hello, worl!" is stored in static memory
    /// s1 creates its own std::string object containing that text
    std::string s1{"Hello, world!"};

    ////////// Solution: if the string is just read only, then use the non-owning std::string_view
    std::string_view sv2{"Hello, world!"};

    ////////// Bad example
    std::string_view sv{};

    { // create a nested block
        std::string s{ "Hello, world!" }; // create a std::string local to this nested block
        sv = s; // sv is now viewing s
    } // s is destroyed here, so sv is now viewing an invalid string

    std::cout << sv << '\n'; // undefined behavior

    return 0;
}
