#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iterator>
# include "iterator_traits.hpp"

namespace ft
{
    template <class T>
    class random_access_iterator
    {
        public:
            typedef ft::Iterator<std::random_access_iterator_tag, T>::value_type        value_type;
            typedef ft::Iterator<std::random_access_iterator_tag, T>::difference_type   difference_type;
            typedef ft::Iterator<std::random_access_iterator_tag, T>::pointer           pointer;
            typedef ft::Iterator<std::random_access_iterator_tag, T>::reference         reference;
            typedef ft::Iterator<std::random_access_iterator_tag, T>::iterator_category iterator_category;
        
            rand_access_iterator();
            ~rand_access_iterator();
            rand_access_iterator(const rand_access_iterator & instance);
            rand_access_iterator & operator = (const rand_access_iterator & instance);

        private:
            pointer iter;
    };
}

#endif