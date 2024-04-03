#pragma once

#include <stdexcept>

template<typename T>
class Array {
private:
    T* data;
    unsigned int size_;

public:
    Array() : data(nullptr), size_(0) {}

    ~Array() {delete[] data;}

    Array(const Array& other) : size_(other.size_) {
        data = new T[size_];
        for (unsigned int i = 0; i < size_; ++i) {
            data[i] = other.data[i];
        }
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] data;
            size_ = other.size_;
            data = new T[size_];
            for (unsigned int i = 0; i < size_; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }


    // Constructeur avec paramètre de type unsigned int n
    Array(unsigned int n) : size_(n) {
        data = new T[size_];
    }

    // Opérateur d'indice
    T& operator[](unsigned int index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Fonction membre size()
    unsigned int size() const {
        return size_;
    }
};
