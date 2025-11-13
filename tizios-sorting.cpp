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

#include <iostream>
using namespace std;

inline unsigned int swap(double& n, double& m) {
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

// --------------------------------------------------------------------------------------------------------------------------------------------- //
// Cocktail sort
// best case: O(n)
// worst case: O(n^2)
// Returns the amount of steps taken to sort the array (comparisons + assignments)
unsigned int cocktail_sort(double *arr, unsigned int size) {
	unsigned int steps = 0;
	if (size <= 1) return steps;

	bool swapped; // Remembers if we swapped during the current cycle
	unsigned int high = size-1;
	unsigned int low = 0;
	do {
		swapped = false; // Reset swapped

		// Forward swap
		for (unsigned int i=low; i<high; i++) {
			steps++;
			if (arr[i] > arr[i+1]) { // Bubble up
				steps += swap(arr[i], arr[i+1]);
				// We don't need to see if the forward swap did something, because the only one that is needed is the backward swap
			} // if closure
		} // forward swap closure
		high--; // Decrease the upper limit since the last element is already in place

		// Backward swap
		for (unsigned int i=high; i>low; i--) {
			steps++;
			if (arr[i] < arr[i-1]) { // Bubble down
				steps += swap(arr[i], arr[i-1]);
				// If the backward swap changed something, it means that the array is still not sorted
				swapped = true;
			} // if closure
		} // backward swap closure
		low++; // Increase the lower limit since the first element is already in place

	} while (swapped == true);

	return steps;
}

// Recursive cocktail sort
// best case: O(n)
// worst case: O(n^2)
// Returns the amount of steps taken to sort the array (comparisons + assignments)
unsigned int recursive_cocktail_sort(double *arr, unsigned int size) {
	unsigned int steps = 0;
	if (size <= 1) return steps;

	bool swapped = false;

	// Forward swap
		for (unsigned int i=0; i<size; i++) {
			steps++;
			if (arr[i] > arr[i+1]) { // Bubble up
				steps += swap(arr[i], arr[i+1]);
				// We don't need to see if the forward swap did something, because the only one that is needed is the backward swap
			} // if closure
		} // forward swap closure

		// Backward swap
		for (unsigned int i=size-1; i>0; i--) { // We skip the last element because we just processed it in the forward swap
			steps++;
			if (arr[i] < arr[i-1]) { // Bubble down
				steps += swap(arr[i], arr[i-1]);
				// If the backward swap changed something, it means that the array is still not sorted
				swapped = true;
			} // if closure
		} // backward swap closure

	// If we didn't swap during the backward swap, then the array is already sorted
	if (!swapped) return steps;

	// We do another cycle where we move the start of array up by 1 and the end of the array down by 1 (basically replacing low/high with 0/size)
	return steps + recursive_cocktail_sort((arr+1), size-1);
}

// --------------------------------------------------------------------------------------------------------------------------------------------- //
// Selection sort
// best case: O(n^2)
// worst case: O(n^2)
// Returns the amount of steps taken to sort the array (comparisons + assignments)
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
// Returns the amount of steps taken to sort the array (comparisons + assignments)
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
// Returns the amount of steps taken to sort the array (comparisons + assignments)
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
// Returns the amount of steps taken to sort the array (comparisons + assignments)
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

// --------------------------------------------------------------------------------------------------------------------------------------------- //
// Insertion sort
// best case: O(n)
// worst case: O(n^2)
// Returns the amount of steps taken to sort the array (comparisons + assignments)
unsigned int insertion_sort(double *arr, unsigned int size) {
	unsigned int steps = 0;
	if (size <= 1) return steps;

	// Process each element
	for (unsigned int i=1; i<size; i++) { // Skip the first element because it's already in the sorted part of the array

		double key = arr[i];

		unsigned int j=i;

		while (j > 0) { // Keep going down until we reach the start of the sorted array
			steps++;
			if (arr[j-1] > key) { // If we find an element bigger than key
				arr[j] = arr[j-1]; // Bubble up it up to make a valid spot for key
				steps++; // Count assignment
				j--;
			} else { // If we find an element smaller than key
				break; // We found the spot for key, break the cycle.
			}
		}

		arr[j] = key; // Place the element at the cell we just freed
		steps++;

	} // for i closure

	return steps;
}

// Recursive insertion sort
// best case: O(n)
// worst case: O(n^2)
// Returns the amount of steps taken to sort the array (comparisons + assignments)
unsigned int recursive_insertion_sort(double *arr, unsigned int size) {
	unsigned int steps = 0;
	if (size <= 1) return steps;

	steps += recursive_insertion_sort(arr, size-1);

	double key = arr[size-1];

	unsigned int j=size-1;

	while (j > 0) { // Keep going down until we reach the start of the sorted array
			steps++;
			if (arr[j-1] > key) { // If we find an element bigger than key
				arr[j] = arr[j-1]; // Bubble up it up to make a valid spot for key
				steps++; // Count assignment
				j--;
			} else { // If we find an element smaller than key
				break; // We found the spot for key, break the cycle.
			}
		}

	arr[j] = key; // Place the element at the cell we just freed
	steps++;

	return steps;
}

// --------------------------------------------------------------------------------------------------------------------------------------------- //
// Shell sort
// best case: O(n log n)
// worst case: O(n^(3/2))
// Returns the amount of steps taken to sort the array (comparisons + assignments)
unsigned int shell_sort(double *arr, unsigned int size) {
	unsigned int steps = 0;
	if (size <= 1) return steps;

	unsigned int gap = size / 2;
	while (gap > 0) {

		// Process each element for the gap size
		for (unsigned int i=gap; i<size; i++) {

			double key = arr[i];
			unsigned int j=i;

			while (j >= gap && arr[j-gap] > key) { // Keep going down until we reach the start of the sorted array
				steps++; // Count comparison (only arr[j-gap] > key, the other is not relevant)
				// If we find an element bigger than key
				arr[j] = arr[j-gap]; // Bubble up it up to make a valid spot for key
				steps++; // Count assignment
				j-=gap; // Go down by gap positions
			}
			steps++; // Count last comparison

			arr[j] = key; // Place the element at the cell we just freed
			steps++; // Count

		} // for i closure

		gap /= 2; // Halve the gap
	}

	return steps;
}

// Recursive Shell sort
// best case: O(n log n)
// worst case: O(n^(3/2))
// Returns the amount of steps taken to sort the array (comparisons + assignments)
unsigned int recursive_shell_sort(double *arr, unsigned int size, unsigned int gap) {
	unsigned int steps = 0;
	if (size <= 1) return steps;

	if (gap == 0) return steps; // Base case

	if (gap > size) gap = size/2;

	// Process each element for the gap size
	for (unsigned int i=gap; i<size; i++) {

		double key = arr[i];
		unsigned int j=i;

		while (j >= gap && arr[j-gap] > key) { // Keep going down until we reach the start of the sorted array
			steps++; // Count comparison (only arr[j-gap] > key, the other is not relevant)
			// If we find an element bigger than key
			arr[j] = arr[j-gap]; // Bubble up it up to make a valid spot for key
			steps++; // Count assignment
			j-=gap; // Go down by gap positions
		}
		steps++; // Count last comparison

		arr[j] = key; // Place the element at the cell we just freed
		steps++; // Count

	} // for i closure

	return steps + recursive_shell_sort(arr, size, gap/2); // Halve the gap
}

// --------------------------------------------------------------------------------------------------------------------------------------------- //
// Gnome sort
// best case: O(n)
// worst case: O(n^2)
// Returns the amount of steps taken to sort the array (comparisons + assignments)
unsigned int gnome_sort(double *arr, unsigned int size) {
	unsigned int steps = 0;
	if (size <= 1) return steps;

	unsigned int i=0;
	while (i < size) {
		if (i == 0) { // If there is no pot on the left, go right
			i++;
		} else {
			steps++; // Count the comparison
			if (arr[i-1] > arr[i]) { // If the left pot is bigger than the right pot, swap them and go back
				steps += swap(arr[i-1], arr[i]); // Count the assignments in the swap
				i--; // Go back 1 pot
			} else { // If the left and the right pot are already in position, go forwards
				i++; // Go forwards 1 pot
			} // else closure
		} // i != 0 closure
	} // while closure

	return steps;
}

//unsigned int recursive_gnome_sort(double *arr, unsigned int size) // Won't do, feel free to open an issue and attach a solution if you want it here

// --------------------------------------------------------------------------------------------------------------------------------------------- //
// Merge sort
/*unsigned int merge_sort(double *arr, unsigned int size) {
	unsigned int steps = 0;
	if (size <= 1) return steps;


	return steps;
}*/

unsigned int recursive_merge_sort(double *arr, unsigned int size) {
	unsigned int steps = 0;
	if (size <= 2) return steps;

	bool isSizeOdd = size % 2 == 1;
	unsigned int halfSize = size/2;
	unsigned int halfSizeOdd = size/2;
	if (isSizeOdd) halfSizeOdd += 1;

	cout << size << endl;

	// Divide into 2 smaller arrays
	steps += recursive_merge_sort(arr, halfSizeOdd);
	steps += recursive_merge_sort(arr + halfSizeOdd, halfSize);

	double* smallArr1 = arr;
	double* smallArr2 = arr + halfSize;

	// New array
	double newArray[size];
	unsigned int i=0, j=0;
	for (unsigned int k=0; k<size; k++) {
		if (i >= halfSize) { // If the first index already reached the end
			// Fill the rest of the array with the content of the second array
			newArray[k] = smallArr2[j];
			j++;
		} else if (j >= halfSizeOdd) { // Otherwise, if the second index already reached the end
			// Fill the rest of the array with the content of the first array
			newArray[k] = smallArr1[i];
			i++;
		}
		else { // Otherwise, if both indices have not reached their max
			if (smallArr1[i] <= smallArr2[j]) { // If the element of the first array is smaller or equal to the element of the second array
				newArray[k] = smallArr1[i]; // Put the element of the first array in the new array
				i++; // Go to the next element of the first array
			} // if arr1[i] > arr2[j] closure
			else { // If the element of the second array is smaller than the element of the first array
				newArray[k] = smallArr2[j]; // Put the element of the second array in the new array
				j++; // Go to the next element of the second array
			} // else closure
		} // if both indices have not reached their max closure

	} // for closure

	// Fill the position of the smaller arrays with the new ordered array
	for (unsigned int i=0; i<size; i++) {
		arr[i] = newArray[i];
	}

	return steps;
}
