#include <iostream>
#include "./header/datastructures.h"
// #include <string>

void testString() {
    // Default constructor
    DS::String s1;

    // Constructor with const char*
    DS::String s2 = "Hello";

    // Copy constructor
    DS::String s3 = s2;

    // Move constructor
    DS::String s4 = std::move(s3);

    // Constructor with initializer_list<char>
    DS::String s5 {'W', 'o', 'r', 'l', 'd'};

    //-------------------------------
    // Test comparison
    // if (s1 == s2) {
    //     std::cout << "s1 is equal to s2" << std::endl;
    // } else {
    //     std::cout << "s1 is not equal to s2" << std::endl;
    // }

    // Test find methods
    // std::size_t pos = s5.find("ini");
    // if (pos != DS::String::npos) {
    //     std::cout << "Found substring \"ini\" in s5 at position " << pos << std::endl;
    // } else {
    //     std::cout << "Substring \"ini\" not found in s5" << std::endl;
    // }

    // Test replace method
    // s5.replace(0, 5, "Replace");
    // std::cout << "s5 after replace: " << s5 << std::endl;

}


int main() 
{
    testString();
    return 0;
}