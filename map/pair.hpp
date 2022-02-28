#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
    template <class T1, class T2> 
    class pair
    {
        //This class couples together a pair of values, which may be of different types (T1 and T2).
        //The individual values can be accessed through its public members first and second.
        //Pairs are a particular case of tuple.
        public:
            typedef T1 first_type;
            typedef T2 second_type;

            first_type  first;
            second_type second;
                    // Member function's
            pair() : first(T1()), second(T2())
            {

            }

            template<class T1, class T2>
            pair (const pair<T1, T2>& pr) : first(T1()), second(T2())
            {
                *this = pr;
            }

            pair (const first_type& a, const second_type& b) : first(a), second(b)
            {

            }

            template<class T1, class T2>
            pair& operator= (const pair<T1, T2>& pr)
            {
                first = pr.first;
                second = pr.second;
                return *this;
            }
                template <class U1, class U2>
            friend bool operator== (const pair<U1,U2>& lhs, const pair<U1,U2>& rhs);
                template <class U1, class U2>
            friend bool operator!= (const pair<U1,U2>& lhs, const pair<U1,U2>& rhs);
                template <class U1, class U2>
            friend bool operator<  (const pair<U1,U2>& lhs, const pair<U1,U2>& rhs);
                template <class U1, class U2>
            friend bool operator<= (const pair<U1,U2>& lhs, const pair<U1,U2>& rhs);
                template <class U1, class U2>
            friend bool operator>  (const pair<U1,U2>& lhs, const pair<U1,U2>& rhs);
                template <class U1, class U2>
            friend bool operator>= (const pair<U1,U2>& lhs, const pair<U1,U2>& rhs);
    };

            // Non-member function's
    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    }	

    template <class T1, class T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (!(lhs == rhs));
    }

    template <class T1, class T2>
    bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
    }

    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (!(rhs<lhs));
    }

    template <class T1, class T2>
    bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (rhs < lhs);
    }

    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (!(lhs < rhs));
    }

    //Constructs a pair object with its first element set to x and its second element set to y.
    //The template types can be implicitly deduced from the arguments passed to make_pair.
    //pair objects can be constructed from other pair objects containing different types,
    //if the respective types are implicitly convertible.
    template <class T1,class T2>
    pair<T1,T2> make_pair (T1 x, T2 y)
    {
        return ( pair<T1,T2>(x,y) );
    }
}

#endif