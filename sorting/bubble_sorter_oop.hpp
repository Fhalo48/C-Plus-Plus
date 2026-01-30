#ifndef BUBBLE_SORTER_OOP_HPP
#define BUBBLE_SORTER_OOP_HPP

#include <iostream>
#include <memory>
#include <vector>

#include "sort_strategy_oop.hpp"

// Context class in the Strategy Pattern
class Sorter {
 private:
    std::shared_ptr<SortStrategy> strategy;

 public:
    explicit Sorter(std::shared_ptr<SortStrategy> strat) : strategy(strat) {}

    void setStrategy(std::shared_ptr<SortStrategy> strat) { strategy = strat; }

    void sortArray(std::vector<int>& arr) {
        if (strategy) {
            strategy->sort(arr);
        }
    }

    void printArray(const std::vector<int>& arr) const {
        for (int i = 0; i < arr.size(); ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif  // BUBBLE_SORTER_OOP_HPP
