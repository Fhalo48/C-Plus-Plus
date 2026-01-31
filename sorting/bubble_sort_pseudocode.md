// Class that encapsulates bubble sort behavior
class Sorter
    // Constructor accepts an optional comparator function
    // comparator(a, b) should return:
    //   negative if a < b, zero if a == b, positive if a > b
    // If no comparator is provided, use default ascending comparator
    constructor(comparator = null)
        if comparator is null
            this.comparator = this.defaultComparator
        else
            this.comparator = comparator

    // Default comparator for ascending numeric or lexicographic order
    function defaultComparator(a, b)
        if a < b then return -1
        if a > b then return 1
        return 0

    // Swap helper swaps elements at indices i and j in array arr
    function swap(arr, i, j)
        temp = arr[i]
        arr[i] = arr[j]
        arr[j] = temp

    // bubbleSort sorts arr in-place
    // Parameters:
    //   arr: list or array to sort
    //   startIndex: optional start index (default 0)
    //   endIndex: optional end index (default arr.length - 1)
    // Returns:
    //   arr (sorted in-place) for convenience
    function bubbleSort(arr, startIndex = 0, endIndex = null)
        // If endIndex not provided, set to last index
        if endIndex is null
            endIndex = length(arr) - 1

        // Edge cases: empty array or single element
        if startIndex >= endIndex
            return arr

        // Outer loop: we will make multiple passes
        // After each pass the largest unsorted element "bubbles" to its correct place
        n = endIndex - startIndex + 1

        // Optimization: track whether any swaps happened in a pass
        // If no swaps, the array is already sorted and we can stop early
        for pass from 0 to n - 2
            swapped = false

            // Inner loop: compare adjacent pairs up to the last unsorted element
            // Each pass reduces the range by one because the end is sorted
            for i from startIndex to endIndex - pass - 1
                // Use comparator to decide order
                // If comparator(arr[i], arr[i+1]) > 0 then arr[i] should come after arr[i+1]
                if this.comparator(arr[i], arr[i + 1]) > 0
                    // Swap out-of-order elements
                    this.swap(arr, i, i + 1)
                    swapped = true

            // If no swaps occurred, the list is sorted; break early
            if not swapped
                break

        return arr
