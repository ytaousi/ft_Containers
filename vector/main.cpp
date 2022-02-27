# include "vector.hpp"
# include <vector>
# include <algorithm>
# include <memory>

int main()
{
    // Fill constructor is fine but Range constructor is playing games with us
    {
        ft::Vector<char> vec_char(13, 'w');

        ft::Vector<char> cpy_vec(vec_char);

        ft::Vector<char>::iterator it = vec_char.begin();

        for (; it != vec_char.end(); it++)
            std::cout << *it << " ";
    }
    
    // Allocator + custom func to fill the memory area is better
    // {
    //     std::allocator<std::string> _alloc;

    //     std::string * array = _alloc.allocate(100);
        
    //     for (size_t j = 0; j < 100; j++)
    //         _alloc.construct(array + j, "Geeks");
    //     size_t j = 0;
    //     for (std::string::iterator it = array[j].begin(); it != array[j].end(); ++it)
    //     { 
    //         std::cout << *it << " ";
    //         j++;
    //     }
    //     std::cout << '\n';
    // }
    return (0);
}