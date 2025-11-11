#include "tizios-sorting.h"

void swap(double& n, double& m) {
    double hold = n;
    n = m;
    m = hold;
}

// Bubble sort
// best case: O(n)
// worst case: O(n^2)
// returns the amount of steps taken to sort the array (comparisons + swaps)
unsigned int bubble_sort(double arr[], unsigned int size) {

    int steps = 0;
    if (size <= 1) return steps;

    for (unsigned int j=0; j<size-1; j++) { // Repeat for the amount of moves at max an element will have to do to reach its position
        // Bool to detect if we swapped during this cycle
        bool swapped = false;
        // Travel through the whole array, and swap i with i+1 if they are in the wrong order
        for (unsigned int i=0; i<size-1-j; i++) { // For each element except the last and the already sorted ones
            if (arr[i] > arr[i+1]) { // If the current element is bigger than the next
                // Swap the elements
                swap(arr[i], arr[i+1]);
                swapped = true; // We swapped an element, so the array was not sorted
                steps++; // Increase the steps for each swap
            } // if closure
            steps++; // Increase the steps for each comparison
        } // for i closure

        if (!swapped) return steps; // If we didn't swap, it means that the array is already sorted, and that we can leave.
    } // for j closure

    return steps;
} // bubble_sort

// Recursive bubble sort
// best case: O(n)
// worst case: O(n^2)
// Returns the amount of steps taken to sort the array (comparisons + swaps)
unsigned int recursive_bubble_sort(double arr[], unsigned int size) {
    unsigned int steps = 0;

    if (size <= 1) return steps; // If the size of the array is 1 or lower, we cannot sort it

    // Bool to detect if we swapped during this cycle
    bool swapped = false;
    for (unsigned int i=0; i<size-1; i++) { // For each element we still have to sort
        if (arr[i] > arr[i+1]) { // If the current element is bigger than the next one
            // Swap the elements
            swap(arr[i], arr[i+1]);
            swapped = true;
            steps++; // Increase the steps for each swap
        }
        steps++; // Increase the steps for each comparison
    } // for closure
    if (!swapped) return steps; // If we didn't swap, the array is already sorted

    // Restart the function, but excluding the last element of the current array (which is already sorted)
    return steps + recursive_bubble_sort(arr, size-1);
} // recursive_bubble_sort() closure

// Selection sort
// best case: O(n^2)
// worst case: O(n^2)
// Returns the amount of steps taken to sort the array (comparisons + swaps)
unsigned int selection_sort(double arr[], unsigned int size) {
    unsigned int steps = 0;
    if (size <= 1) return steps;

    double min;
    unsigned int minIndex;

    for (unsigned int i=0; i<size-1; i++) { // We skip the last iteration since it's already gonna be in place
        min = arr[i]; // Set the minimum value as the first safe one
        minIndex = i; // Pair the index with it
        // We search for the minimum element from i (we already processed i with min = arr[i])
        for (unsigned int j=i+1; j<size; j++) { // Search min in [i+1, size-1)
            if (arr[j] < min) { // If we found a new min, we save it
                min = arr[j];
                minIndex = j;
            } // if closure
            steps++; // Increase the steps for each comparison
        } // for j closure
        if (i != minIndex) { // If the minimum value is not the first element
            // We put our minimum value to the start of the piece of array we are sorting
            swap(arr[i], arr[minIndex]);
            steps++; // Increase the steps for each swap
        } // if closure
    } // for i closure

    return steps;
} // selection_sort() closure

// Recursive selection sort
// best case: O(n^2)
// worst case: O(n^2)
// Returns the amount of steps taken to sort the array (comparisons + swaps)
unsigned int recursive_selection_sort(double arr[], unsigned int size) {
    unsigned int steps = 0;
    if (size <= 1) return steps; // Base case
    return steps;
}