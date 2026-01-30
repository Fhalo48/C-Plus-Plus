#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

#include <vector>

#include "SortStrategy.hpp"

// Concrete implementation of the bubble sort strategy
class BubbleSort : public SortStrategy {
 public:
    void sort(std::vector<int>& arr) override;
};

#endif  // BUBBLESORT_HPP
