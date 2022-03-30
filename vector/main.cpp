# include "vector.hpp"
# include <vector>
# include <iostream>

int main ()
{
    std::cout << "******************** std::vector::clear ********************************" << std::endl;
    std::cout << "************************************************************************" << std::endl;
    std::vector<int> std_vector;
    std_vector.push_back (100);
    std_vector.push_back (200);
    std_vector.push_back (300);

    std::cout << "std_vector contains:";
    for (unsigned i = 0; i < std_vector.size(); i++)
        std::cout << ' ' << std_vector[i];
    std::cout << '\n';

    std_vector.clear();
    std_vector.push_back (1101);
    std_vector.push_back (2202);

    std::cout << "std_vector contains:";
    for (unsigned i=0; i<std_vector.size(); i++)
        std::cout << ' ' << std_vector[i];
    std::cout << '\n';

    std::cout << "********************** ft::Vector::clear ***************************" << std::endl;

    ft::Vector<int> my_vector;
    my_vector.push_back (100);
    my_vector.push_back (200);
    my_vector.push_back (300);

    std::cout << "my_vector contains:";
    for (unsigned i = 0; i < my_vector.size(); i++)
        std::cout << ' ' << my_vector[i];
    std::cout << '\n';

    my_vector.clear();
    my_vector.push_back (1101);
    my_vector.push_back (2202);

    std::cout << "my_vector contains:";
    for (unsigned i = 0; i < my_vector.size(); i++)
        std::cout << ' ' << my_vector[i];
    std::cout << '\n';

    std::cout << "*********************** std::vector::swap ******************************" << std::endl;
    std::cout << "************************************************************************" << std::endl;

    std::vector<int> std_foo (3,100);   // three ints with a value of 100
    std::vector<int> std_bar (5,200);   // five ints with a value of 200

    std_foo.swap(std_bar);

    std::cout << "std_foo contains:";
    for (unsigned i=0; i<std_foo.size(); i++)
        std::cout << ' ' << std_foo[i];
    std::cout << '\n';

    std::cout << "std_bar contains:";
    for (unsigned i=0; i<std_bar.size(); i++)
        std::cout << ' ' << std_bar[i];
    std::cout << '\n';

    std::cout << "*********************** ft::Vector::swap ***************************************" << std::endl;

    ft::Vector<int> my_foo (3,100);   // three ints with a value of 100
    ft::Vector<int> my_bar (5,200);   // five ints with a value of 200

    my_foo.swap(my_bar);

    std::cout << "my_foo contains:";
    for (unsigned i=0; i<my_foo.size(); i++)
        std::cout << ' ' << my_foo[i];
    std::cout << '\n';

    std::cout << "my_bar contains:";
    for (unsigned i=0; i<my_bar.size(); i++)
        std::cout << ' ' << my_bar[i];
    std::cout << '\n';

    std::cout << "*********************** std::vector::erase *****************************" << std::endl;
    std::cout << "************************************************************************" << std::endl;

    std::vector<int> stdvector;

    // set some values (from 1 to 10)
    for (int i=1; i<=10; i++) stdvector.push_back(i);

    // erase the 6th element
    stdvector.erase (stdvector.begin()+5);

    // erase the first 3 elements:
    stdvector.erase (stdvector.begin(),stdvector.begin()+3);

    std::cout << "stdvector contains:";
    for (unsigned i=0; i<stdvector.size(); ++i)
        std::cout << ' ' << stdvector[i];
    std::cout << '\n';

    std::cout << "************************** ft::Vector::erase *********************************" << std::endl;
  
    ft::Vector<int> myvector;

    // set some values (from 1 to 10)
    for (int i=1; i<=10; i++) myvector.push_back(i);

    // erase the 6th element
    myvector.erase (myvector.begin() + 5);

    // erase the first 3 elements:
    myvector.erase (myvector.begin(),myvector.begin() + 3);

    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector.size(); ++i)
        std::cout << ' ' << myvector[i];
    std::cout << '\n';

    std::cout << "*********************** std::vector::insert ****************************" << std::endl;
    std::cout << "************************************************************************" << std::endl;

    std::vector<int> myvector (3,100);
    std::vector<int>::iterator it;

    it = myvector.begin();
    it = myvector.insert ( it , 200 );

    myvector.insert (it,2,300);

    // "it" no longer valid, get a new one:
    it = myvector.begin();

    std::vector<int> anothervector (2,400);
    myvector.insert (it+2,anothervector.begin(),anothervector.end());

    int myarray [] = { 501,502,503 };
    myvector.insert (myvector.begin(), myarray, myarray+3);

    std::cout << "myvector contains:";
    for (it=myvector.begin(); it<myvector.end(); it++)
        std::cout << ' ' << *it;
    std::cout << '\n';


    std::cout << "*************************************************************************" << std::endl;

  return 0;
}