#ifndef VPRINT_H
#define VPRINT_H

#include <iostream>
#include <vector>

template<typename T>
void Vprint (const std::vector<T> & vec_to_print)
{
    std::cout << "[ ";
    for (auto i :vec_to_print)
        std::cout << i << " ";
    std::cout << "]" << std::endl;
}

#endif