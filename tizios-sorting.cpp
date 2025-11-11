#include "tizios-sorting.h"

/*
----------- COUNTING RULES -------------
Count comparisons once immediately before.
Count each assignment of a scalar as 1.
swap(...) returns the number of assignments it did (3) and we add that.
We don't count operations outside of loops.
We do not add extra steps++ outside those operations.
----------------------------------------
*/


unsigned int swap(double& n, double& m) {
    double hold = n;
    n = m;
    m = hold;
    return 3;
}

// Bubble sort
// best case: O(n)
// worst case: O(n^2)
// returns the amount of steps taken to sort the array (assignments and comparisons)
unsigned int bubble_sort(double arr[], unsigned int size) {

    int steps = 0;
    if (size <= 1) return steps;

    for (unsigned int j=0; j<size-1; j++) { // Repeat for the amount of moves at max an element will have to do to reach its position
        // Bool to detect if we swapped during this cycle
        bool swapped = false;
        // Travel through the whole array, and swap i with i+1 if they are in the wrong order
        for (unsigned int i=0; i<size-1-j; i++) { // For each element except the last and the already sorted ones
            steps++; // Increase the steps for each comparison
            if (arr[i] > arr[i+1]) { // If the current element is bigger than the next
                // Swap the elements
                steps += swap(arr[i], arr[i+1]); // Increase the steps for each assignment
                swapped = true; // We swapped an element, so the array was not sorted
            } // if closure
        } // for i closure

        if (!swapped) return steps; // If we didn't swap, it means that the array is already sorted, and that we can leave.
    } // for j closure

    return steps;
} // bubble_sort

// Recursive bubble sort
// best case: O(n)
// worst case: O(n^2)
// Returns the amount of steps taken to sort the array (assignments and comparisons)
unsigned int recursive_bubble_sort(double arr[], unsigned int size) {
    unsigned int steps = 0;

    if (size <= 1) return steps; // If the size of the array is 1 or lower, we cannot sort it

    // Bool to detect if we swapped during this cycle
    bool swapped = false;
    for (unsigned int i=0; i<size-1; i++) { // For each element we still have to sort
        steps++; // Increase the steps for each comparison
        if (arr[i] > arr[i+1]) { // If the current element is bigger than the next one
            // Swap the elements
            steps += swap(arr[i], arr[i+1]); // Increase the steps for each assignment inside swap().
            swapped = true;
        }
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
        steps += 2; // Increase the steps for each assignment

        // We search for the minimum element from i (we already processed i with min = arr[i])
        for (unsigned int j=i+1; j<size; j++) { // Search min in [i+1, size-1)

            steps++; // Increase the steps for each comparison
            if (arr[j] < min) { // If we found a new min, we save it

                min = arr[j];
                minIndex = j;
                steps += 2; // Increase the steps for each assignment

            } // if closure
        } // for j closure

        steps++;
        if (i != minIndex) { // If the minimum value is not the first element already
            // We put our minimum value to the start of the piece of array we are sorting
            steps += swap(arr[i], arr[minIndex]); // Increase the steps for each assignment in swap()
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

    // We find the highest element and put it at the end of our array.
    double min = arr[0];
    unsigned int minIndex = 0;
    steps += 2; // Increase the steps for each assignment

    for (unsigned int j=0; j<size; j++) { // For each element of the array we still have to sort (we already processed the last index)

        steps++; // Increase the steps for each comparison
        if (arr[j] < min) { // If we found a new max, we save it

            min = arr[j];
            minIndex = j;
            steps += 2; // Increase the steps for each assignment

        } // if closure

    } // for j closure

    if (minIndex != 0) { // If the maximum value is not the last element already
        // We put our maximum value to the end of the piece of array we are sorting
        steps += swap(arr[minIndex], arr[0]); // Increase the steps for each assignment in swap()
    }

    // We restart the function to process all the non-sorted elements (everything except the last element)
    return steps + recursive_selection_sort(arr+1, size-1);
}

// Selection sort (checks for max instead of min)
// best case: O(n^2)
// worst case: O(n^2)
// Returns the amount of steps taken to sort the array (comparisons + swaps)
unsigned int selection_sort_using_max(double arr[], unsigned int size) {
    unsigned int steps = 0;
    if (size <= 1) return steps;

    const unsigned int lastIndex = size-1;

    double max;
    unsigned int maxIndex;

    for (unsigned int i=0; i<lastIndex; i++) { // We skip the last iteration since it's already gonna be in place

        max = arr[lastIndex-i]; // Set the maximum value as the first safe one (in this case the last value)
        maxIndex = lastIndex-i; // Pair the index with it
        steps += 2; // Increase the steps for each assignment

        // We search for the minimum element from i (we already processed i with min = arr[i])
        for (unsigned int j=0; j<lastIndex-i; j++) { // Search min in [0, lastIndex-i)

            steps++; // Increase the steps for each comparison
            if (arr[j] > max) { // If we found a new min, we save it

                max = arr[j];
                maxIndex = j;
                steps += 2; // Increase the steps for each assignment

            } // if closure
        } // for j closure

        if (lastIndex-i != maxIndex) { // If the minimum value is not the first element already
            // We put our minimum value to the start of the piece of array we are sorting
            steps += swap(arr[lastIndex-i], arr[maxIndex]); // Increase the steps for each assignment in swap()
        } // if closure

    } // for i closure

    return steps;
} // selection_sort() closure

// Recursive selection sort (checks for max instead of min)
// best case: O(n^2)
// worst case: O(n^2)
// Returns the amount of steps taken to sort the array (comparisons + swaps)
unsigned int recursive_selection_sort_using_max(double arr[], unsigned int size) {
    unsigned int steps = 0;
    if (size <= 1) return steps; // Base case

    const unsigned int lastIndex = size-1;

    // We find the highest element and put it at the end of our array.
    double max = arr[lastIndex];
    unsigned int maxIndex = lastIndex;
    steps += 2; // Increase the steps for each assignment

    for (unsigned int j=0; j<lastIndex; j++) { // For each element of the array we still have to sort (we already processed the last index)

        steps++; // Increase the steps for each comparison
        if (arr[j] > max) { // If we found a new max, we save it

            max = arr[j];
            maxIndex = j;
            steps += 2; // Increase the steps for each assignment

        } // if closure

    } // for j closure

    if (maxIndex != lastIndex) { // If the maximum value is not the last element already
        // We put our maximum value to the end of the piece of array we are sorting
        steps += swap(arr[maxIndex], arr[lastIndex]); // Increase the steps for each assignment in swap()
    }

    // We restart the function to process all the non-sorted elements (everything except the last element)
    return steps + recursive_selection_sort_using_max(arr, size-1);
}