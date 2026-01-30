#include "quick_sort_oop.hpp"

// Partition function for quick sort
int QuickSort::partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Implementation of the quick sort strategy
void QuickSort::sort(std::vector<int>& arr) {
    if (arr.empty()) {
        return;
    }
    quickSortHelper(arr, 0, arr.size() - 1);
}

// Helper function for recursive quick sort
void QuickSort::quickSortHelper(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}
