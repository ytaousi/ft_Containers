#include <iostream>     
#include <iterator>     // std::iterator, std::input_iterator_tag
#include <vector>

class MyIterator : public std::iterator<std::input_iterator_tag, int>
{
    int* p;
    public:
        MyIterator(int* x) :p(x)
        {}
        MyIterator(const MyIterator& mit) : p(mit.p)
        {}
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


int main () {
//   int numbers[]={10,20,30,40,50};
//   MyIterator from(numbers);
//   MyIterator until(numbers+5);
//   for (MyIterator it=from; it!=until; it++)
//     std::cout << *it << ' ';
  std::cout << "\n******************************************";

    std::vector<int> myvector;
  for (int i=0; i<10; i++)
    myvector.push_back(i);

  typedef std::vector<int>::iterator iter_type;
                                                         // ? 0 1 2 3 4 5 6 7 8 9 ?
  iter_type from (myvector.begin());                     //   ^
                                                         //         ------>
  iter_type until (myvector.end());                      //                       ^
                                                         //
  std::reverse_iterator<iter_type> rev_until (from);     // ^
                                                         //         <------
  std::reverse_iterator<iter_type> rev_from (until);     //                     ^

  std::cout << "myvector:";
  while (rev_from != rev_until)
    std::cout << ' ' << *rev_from++;
  std::cout << '\n';
  return 0;
}