#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <list>

template <typename T>
void mergeInsertSort(std::vector<T>& vec);

template <typename T>
void mergeInsertSort(std::list<T>& lst);

#include "PmergeMe.cpp" // Include the source file here to allow explicit instantiation
#endif // PMERGE_ME_HPP
