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
    ~MyIterator() {std::cout << "Destructor Called" << std::endl;};
      MyIterator() : p(NULL)
      {
        std::cout << "Empty constructor Called MyIterator() :" << std::endl;
        std::cout << "value of p (& object pointed to)= " << p << std::endl;
      };
      MyIterator(int* x) :p(x)
      {
        std::cout << "Constructor with parameter Called MyIterator(int * x)" << std::endl;
        std::cout << "value of x (&value) = ["<< x << "] " << "\naddress of x (pointer passed to construct) = [" << &x << " <= this is an address of the copy passed as a prameter]" << std::endl;  
        std::cout << "value of p (object constructed from int *x , p(x) ) = [" << p << "]" << "\naddress of p (&p) = [" << &p << "]" << std::endl;
        std::cout << "value of this (address of internal  pointer  p) = [" << this << "]" << std::endl;
      
      }
      MyIterator(const MyIterator& instance) : p(instance.p)
      {
        std::cout << "Copy constructor Called" << '\n';
        *this = instance;
      }

      MyIterator & operator = (const MyIterator & instance)
      {
        std::cout << "Assignement Operator Called" << '\n'; 
        return *this;
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
  int numbers[]={10,20,30,40,50};
  MyIterator from(numbers);
  MyIterator until(numbers+5);
  for (MyIterator it=from; it!=until; it++)
    std::cout << *it << ' ';
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
  
  int value = 5;
  std::cout << "value = " << value << "\naddress of value(&value) = [" << &value << "]" << std::endl;
  
  int * pointer = &value;
  std::cout << "*pointer = " << *pointer << "\naddress of pointer(&pointer) = [" << &pointer << "]" << "\nvalue of pointer (pointer = &value) = [" << pointer << "]" << std::endl;

  std::cout << "\n******************************************\n";
  MyIterator iterator(pointer);
  std::cout << "\n******************************************\n";

  std::vector<int> array;

  for (MyIterator it = array.begin(); it != array.end(); it ++)
    array.push_back(*it);
  
  return 0;
}