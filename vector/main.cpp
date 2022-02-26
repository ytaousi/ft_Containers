# include "vector.hpp"
# include <vector>
# include <algorithm>
# include <memory>

int main()
{
    // Fill constructor is fine but Range constructor is playing games with us
    // {
    //     {
    //         ft::Vector<std::string> vec1(10, "Nooooooooooooob");
    //     }

    // //    for (ft::Vector<std::string>::iterator it = vec1.begin(); it != vec1.end(); ++it)
    // //    {
    // //        std::cout << *it << " ";
    // //    }
    //     std::cout << "\n*****************************************************************************" << std::endl;
        
    //     ft::Vector<std::string> vec1(100, "You do it");
    //     ft::Vector<std::string> vec2(vec1.begin(), vec1.end());

    // //for (ft::Vector<std::string>::iterator it = vec2.begin(); it != vec2.end(); ++it)
    // //{
    // //   std::cout << *it << " ";
    // //}
    // }
    
    // Allocator + custom func to fill the memory area is better
    {
        std::allocator<std::string> _alloc;

        std::string * array = _alloc.allocate(100);
        
        for (size_t j = 0; j < 100; j++)
            _alloc.construct(array + j, "Geeks");
        size_t j = 0;
        for (std::string::iterator it = array[j].begin(); it != array[j].end(); ++it)
        { 
            std::cout << *it << " ";
            j++;
        }
        std::cout << '\n';
    }
    return (0);
}