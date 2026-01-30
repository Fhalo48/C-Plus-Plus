#include <iostream>
#include <memory>
#include <vector>

#include "BubbleSort.hpp"

// Implementation of the bubble sort strategy
void BubbleSort::sort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Sorter class - Context in the Strategy Pattern
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

int main() {
    // Create a concrete strategy
    auto bubbleSort = std::make_shared<BubbleSort>();

    // Create a Sorter (Context) with the strategy
    Sorter sorter(bubbleSort);

    // Example usage with Strategy Pattern
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    std::cout << "Unsorted array: ";
    sorter.printArray(arr);

    // Use the sorter with bubble sort strategy
    sorter.sortArray(arr);

    std::cout << "Sorted array: ";
    sorter.printArray(arr);

    return 0;
}
