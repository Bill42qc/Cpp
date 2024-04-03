#include "Span.hpp"

Span::Span(unsigned int size) : _size(size) {}
Span::~Span() {}

Span::Span(const Span &other) : _size(other._size), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _size = other._size;
        _numbers = other._numbers;
    }
    return *this;
}

void Span::addNumber(int number) {
    if (_numbers.size() >= _size)
        throw std::overflow_error("Span is full");
    _numbers.push_back(number);
}

//inding the maximum absolute difference between any two elements in the stored collection of integers.
int Span::shortestSpan() const {
    if (_numbers.size() <= 1)
        throw std::runtime_error("Not enough elements to find span");
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 2; i < sorted.size(); ++i) {
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() <= 1)
        throw std::runtime_error("Not enough elements to find span");
    return *std::max_element(_numbers.begin(), _numbers.end()) - *std::min_element(_numbers.begin(), _numbers.end());
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    size_t distance = std::distance(begin, end); // Convert to unsigned type
    if (distance > _size - _numbers.size())
        throw std::overflow_error("Adding range would exceed span capacity");
    _numbers.insert(_numbers.end(), begin, end);
}

