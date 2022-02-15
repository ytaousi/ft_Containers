#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iterator>
# include "iterator_traits.hpp"

namespace ft
{
    template <class value_type>
    class random_access_iterator
    {
        public:
            typedef ft::Iterator<std::random_access_iterator_tag, T>::value_type        value_type;
            typedef ft::Iterator<std::random_access_iterator_tag, T>::difference_type   difference_type;
            typedef ft::Iterator<std::random_access_iterator_tag, T>::pointer           pointer;
            typedef ft::Iterator<std::random_access_iterator_tag, T>::reference         reference;
            typedef ft::Iterator<std::random_access_iterator_tag, T>::iterator_category iterator_category;
        
            rand_acc_iterator();
            ~rand_acc_iterator();
            rand_acc_iterator(const rand_acc_iterator & instance);
            rand_acc_iterator & operator = (const rand_acc_iterator & instance);

        private:
            pointer iter;
    };
}

#endif