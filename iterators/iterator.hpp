#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iterator>
# include "iterator_traits.hpp"

namespace ft
{
    template <class T>
    class rand_acc_iterator : ft::iterator<std::random_access_iterator_tag, T>
    {
        public:
            typedef ft::iterator<std::random_access_iterator, T>::value_type        value_type;
            typedef ft::iterator<std::random_access_iterator, T>::difference_type   difference_type;
            typedef ft::iterator<std::random_access_iterator, T>::pointer           pointer;
            typedef ft::iterator<std::random_access_iterator, T>::reference         reference;
            typedef ft::iterator<std::random_access_iterator, T>::iterator_category iterator_category;
        
            rand_acc_iterator();
            ~rand_acc_iterator();
            rand_acc_iterator(const rand_acc_iterator & instance);
            rand_acc_iterator & operator = (const rand_acc_iterator & instance);

        private:
            pointer iter;
    };
}

#endif