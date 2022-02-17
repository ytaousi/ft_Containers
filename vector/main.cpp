#include "vector.hpp"

int main()
{
    //ft::vector<int> first;

    ft::vector<int> second(6, 7);
    
    //std::cout << first.size() << std::endl;
    std::cout << second.size() << "\n" << second[0] << "\n" << second[1] << std::endl;
    return (0);
}