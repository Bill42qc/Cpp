#pragma once

#include <iostream>
#include <stdexcept> 

template<typename T, typename Func>
void iter(T* array, int size, Func func) {
    if (size < 0) {
        throw std::invalid_argument("Size must be positive.");
    }
        if (size == 0) {
          return;
        }

    for (int i = 0; i < size; ++i) {
        func(array[i]);
    }
}
