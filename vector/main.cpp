#include "vector.hpp"
#include <vector>
#include <algorithm>

int main()
{
    ft::vector<std::string> first(5, "Noob");
    //ft::vector<std::string> second(first);
    //ft::vector<std::string> third = second;

    for (size_t i = 0; i < 5; i++)
        std::cout << first[i] << std::endl;
    std::cout << "*********************************" << std::endl;
    // for (size_t i = 0; i < 5; i++)
    //    std::cout << second[i] << std::endl;
    // std::cout << "*********************************" << std::endl;
    // for (size_t i = 0; i < 5; i++)
    //    std::cout << third[i] << std::endl; 
    
    return (0);
}