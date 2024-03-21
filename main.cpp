#include <iostream>
#include "./header/datastructures.h"
#include <cassert>

int main()
{
    // DS::Vector<int> v2(5);
    // assert(!v2.empty());
    // assert(v2.size() == 5);

    // DS::Vector<int> v12 = {1, 2, 3};
    // DS::Vector<int> v13 = {1, 2, 4};
    // assert(v12 != v13);
    // assert(!(v12 == v13));

    // DS::Vector<int> v14 = {1, 2, 3};
    // DS::Vector<int> v15 = {1, 2, 4};
    // assert(v14 < v15);
    // assert(v14 <= v15);
    // assert(!(v15 < v14));
    // assert(!(v15 <= v14));
    // assert(v15 > v14);
    // assert(v15 >= v14);
    // assert(!(v14 > v15));
    // assert(!(v14 >= v15));

    // Test Iterators
    // DS::Vector<int> v16 = {1, 2, 3};


    // Test Const Reverse Iterator
    // DS::Vector<int>::Const_Reverse_Iterator rit1 = v16.crbegin();
    // ++rit1;
    // --rit1;
    // rit1++;
    // rit1--;
    // rit1 += 2;
    // rit1 -= 2;
    // assert(rit1[1] == 2);

    // Test Reverse Iterator
    // DS::Vector<int>::Reverse_Iterator rit2 = v16.rbegin();
    // ++rit2;
    // --rit2;
    // rit2++;
    // rit2--;
    // rit2 += 2;
    // rit2 -= 2;
    // assert(rit2[1] == 2);
    
    return 0;
}