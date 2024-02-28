#include "array.hpp"

#include <iostream>

int main()
{
    array a0(5);
    array a1(5, 10.0);
    array a2 = {1, 2, 3, 4, 5};
    array a3 = a2;

    a3[0] = 0.0;

    std::cout << "a0=" << a0.to_string() << std::endl;
    std::cout << "a1=" << a1.to_string() << std::endl;
    std::cout << "a2=" << a2.to_string() << std::endl;
    std::cout << "a3=" << a3.to_string() << std::endl;
}