#include "vector.hpp"
#include <vector>
#include <algorithm>

int main()
{
    ft::vector<int> first(14, 4);
    std::vector<int> second (14, 23);

    for (size_t i = 0; i < 14; i++)
        std::cout << first[i] << std::endl;
    std::cout << "*********************************" << std::endl;
    for (size_t i = 0; i < 14; i++)
        std::cout << second[i] << std::endl;
    return (0);
}