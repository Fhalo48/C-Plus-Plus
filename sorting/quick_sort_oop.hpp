#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <vector>

#include "sort_strategy_oop.hpp"

// Concrete implementation of the quick sort strategy
class QuickSort : public SortStrategy {
 public:
    void sort(std::vector<int>& arr) override;

 private:
    int partition(std::vector<int>& arr, int low, int high);
    void quickSortHelper(std::vector<int>& arr, int low, int high);
};

#endif  // QUICKSORT_HPP
