#include "bubble_sort_oop.hpp"

#include <iostream>
#include <memory>
#include <vector>

#include "bubble_sorter_oop.hpp"

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
