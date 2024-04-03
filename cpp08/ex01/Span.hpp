#pragma once

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span {
private:
    unsigned int _size;
    std::vector<int> _numbers;

public:
    Span(unsigned int size);
    ~Span();
    Span(const Span &other);
    Span &operator=(const Span &other);

    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;
    void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};
