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

    std::vector<int> stdd_vector (3,100);
    std::vector<int>::iterator it;

    it = stdd_vector.begin();
    it = stdd_vector.insert ( it , 200 );

    stdd_vector.insert (it,2,300);

    // "it" no longer valid, get a new one:
    it = stdd_vector.begin();

    for (; it != stdd_vector.end(); it++)
        std::cout << " " << *it;
    std::cout << std::endl;

    // std::vector<int> anothervector (2,400);
    // stdd_vector.insert (it+2,anothervector.begin(),anothervector.end());

    // int myarray [] = { 501,502,503 };
    // stdd_vector.insert (stdd_vector.begin(), myarray, myarray+3);

    // std::cout << "stdd_vector contains:";
    // for (it=stdd_vector.begin(); it<stdd_vector.end(); it++)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';


    std::cout << "************************* ft::Vector::insert *************************************" << std::endl;

    ft::Vector<int> myy_vector (3,100);
    ft::Vector<int>::iterator itt;

    itt = myy_vector.begin();
    itt = myy_vector.insert ( itt , 200 );

    myy_vector.insert (itt,2,300);

    // // "itt" no longer valid, get a new one:
    itt = myy_vector.begin();

    for (; itt != myy_vector.end(); itt++)
        std::cout << " " << *itt;
    std::cout << std::endl;
    // std::vector<int> anothervector (2,400);
    // myy_vector.insert (itt+2,anothervector.begin(),anothervector.end());

    // int myarray [] = { 501,502,503 };
    // myy_vector.insert (myy_vector.begin(), myarray, myarray+3);

    // std::cout << "myy_vector contains:";
    // for (itt=myy_vector.begin(); itt<myy_vector.end(); itt++)
    //     std::cout << ' ' << *itt;
    // std::cout << '\n';

    std::cout << "********************************* std::vector::reserve ********************************" << std::endl;
    std::cout << "***************************************************************************************" << std::endl;
    
    std::vector<int>::size_type sz;
    std::vector<int> foo;
    
    sz = foo.capacity();
    std::cout << "making foo grow:\n";
    for (int i=0; i<100; ++i)
    {
        foo.push_back(i);
        if (sz!=foo.capacity())
        {
            sz = foo.capacity();
            std::cout << "capacity changed: " << sz << '\n';
        }
    }

    std::vector<int> bar;
    sz = bar.capacity();
    bar.reserve(100);   // this is the only difference with foo above
    std::cout << "making bar grow:\n";
    for (int i=0; i<100; ++i)
    {
        bar.push_back(i);
        if (sz!=bar.capacity())
        {
            sz = bar.capacity();
            std::cout << "capacity changed: " << sz << '\n';
        }
    }

    std::cout << "********************************* ft::Vector::reserve *********************************" << std::endl;

    ft::Vector<int>::size_type szz;
    ft::Vector<int> foofoo;
    
    szz = foofoo.capacity();
    std::cout << "making foofoo grow:\n";
    for (int i=0; i<100; ++i)
    {
        foofoo.push_back(i);
        if (szz!=foofoo.capacity())
        {
            szz = foofoo.capacity();
            std::cout << "capacity changed: " << szz << '\n';
        }
    }

    std::vector<int> bbar;
    szz = bbar.capacity();
    bbar.reserve(100);   // this is the only difference with foofoo above
    std::cout << "making bbar grow:\n";
    for (int i=0; i<100; ++i)
    {
        bbar.push_back(i);
        if (szz!=bbar.capacity())
        {
            szz = bbar.capacity();
            std::cout << "capacity changed: " << szz << '\n';
        }
    }

    std::cout << "********************************* std::vector::resize *********************************" << std::endl;
    std::cout << "***************************************************************************************" << std::endl;

    std::vector<int> stddd_vector;

    // set some initial content:
    for (int i=1;i<10;i++) stddd_vector.push_back(i);

    stddd_vector.resize(5);
    stddd_vector.resize(8,100);
    stddd_vector.resize(12);

    std::cout << "stddd_vector contains:";
    for (int i=0;i<stddd_vector.size();i++)
        std::cout << ' ' << stddd_vector[i];
    std::cout << '\n';

    std::cout << "********************************** ft::Vector::resize **********************************" << std::endl;

    ft::Vector<int> myyyvector;

    // set some initial content:
    for (int i=1;i<10;i++) myyyvector.push_back(i);

    myyyvector.resize(5);
    myyyvector.resize(8,100);
    myyyvector.resize(12);

    std::cout << "myyyvector contains:";
    for (int i=0;i<myyyvector.size();i++)
        std::cout << ' ' << myyyvector[i];
    std::cout << '\n';
  return 0;
}