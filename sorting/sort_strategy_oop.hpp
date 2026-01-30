#ifndef SORTSTRATEGY_HPP
#define SORTSTRATEGY_HPP

#include <vector>

// Abstract base class for sorting strategies
class SortStrategy {
 public:
    virtual ~SortStrategy() = default;
    virtual void sort(std::vector<int>& arr) = 0;
};

#endif  // SORTSTRATEGY_HPP
