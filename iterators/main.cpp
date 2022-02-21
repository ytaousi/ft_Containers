#include <iostream>     
#include <iterator>     // std::iterator, std::input_iterator_tag
#include <vector>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "iterator_traits.hpp"

class MyIterator : public std::iterator<std::random_access_iterator_tag, int> // only input iterator featurs implemented
{
  typedef int * iterator_type;
  iterator_type p;
    public:
      MyIterator() : p(nullptr)
      {
        std::cout << "Empty constructor Called" << std::endl;
        std::cout << "*p = nullptr\n";
      };
      MyIterator(int* x) :p(x)
      {
        std::cout << " x = p / \n";
        std::cout << "address of x: ["<< x << "] " << "address of p(object constructed from x) [" << p << "]" << std::endl;  
      }
      MyIterator(const MyIterator& mit) : p(mit.p)
      {
        std::cout << "Copy constructor Called" << '\n';
      }

      const iterator_type & getBasePointer() const
      {
        return p;
      }
      // Input iterator operation with the pointer
      MyIterator& operator++()
      {
            ++p;
            return *this;
      }
      MyIterator operator++(int)
      {
          MyIterator tmp(*this);
          operator++();
          return tmp;
      }
      bool operator==(const MyIterator& rhs) const
      {
        return p == rhs.p;
      }
      bool operator!=(const MyIterator& rhs) const 
      {
        return p!=rhs.p;
      }
      int& operator*()
      {
        return *p;
      }
};

std::ostream &        operator << (std::ostream & out , const MyIterator & object)
{
  out << object.getBasePointer();
  return out;
}


int main () {
//   int numbers[]={10,20,30,40,50};
//   MyIterator from(numbers);
//   MyIterator until(numbers+5);
//   for (MyIterator it=from; it!=until; it++)
//     std::cout << *it << ' ';
  std::cout << "\n******************************************\n";

  //   std::vector<int> myvector;
  // for (int i=0; i<10; i++)
  //   myvector.push_back(i);

  // typedef std::vector<int>::iterator iterator;
  
  // iterator iter(myvector.begin());
  // for (; iter != myvector.end(); iter++)
  //   std::cout << "["<< *iter << "] " ;
  // std::cout << '\n';
  
  // iterator from (myvector.begin());
  // iterator until (myvector.end());
                              
  // typedef std::reverse_iterator<iterator> rev_iterator;
  
  // rev_iterator rev_until (from);
  // rev_iterator rev_from (until);

  // std::cout << "*from :" << *from << " *rev_until:" << *(rev_until) << " *until:" << *until << "*rev_from:" << *rev_from << '\n' ;
  // ++from;
  // ++until;
  // std::cout << "*form/*until:[" << *from << "/" << *until << "]\n" ;

  MyIterator iterator;
  
  int value = 5;

  int * pointer = &value;
  //std::cout << "object.getBasePointer() -> p: *p = " << *(pointer) << std::endl;
  return 0;
}