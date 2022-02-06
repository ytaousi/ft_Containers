#include "stack.hpp"

#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    ft::stack<int> custom_stack;

    std::cout << "stack size: " << custom_stack.size() << std::endl;
    std::cout << "container.empty(): " << custom_stack.empty() << std::endl;
    custom_stack.push(3);
    std::cout << "container.empty(): " << custom_stack.empty() << std::endl;
    std::cout << "stack size: " << custom_stack.size() << std::endl;
    return (0);
}