#include <iostream>
#include "tizios-sorting.h"

using namespace std;

void print_array(double[], unsigned int);
void copy_array_into(double[], double[], unsigned int);
void reset_conditions(double[], double[], unsigned int);
void test_sort_function(const char* name, sort_function_p sort_function, double array[], double backup[], unsigned int size);

int main(int argc, char *argv[]) {

    // Missing arguments error message
    if (argc < 2) {
        cout << "Missing arguments, input at least 2 elements for the array." << endl;
        return 1;
    }

    // Set up the original array
    unsigned int size = argc - 1;
    double array[argc-1] = {};
    double backup[argc-1] = {}; // used to reset the ordered array to the original state

    for (int i=1; i<argc; i++) {
        array[i-1] = atof(argv[i]);
        backup[i-1] = array[i-1];
    }

    // Print the original array
    cout << endl << "Original array:" << endl;
    print_array(array, size);
    cout << endl;

    cout << endl << " ------------------------------------------- " << endl;

    // Order it with bubble sort
    test_sort_function("Bubble Sort", bubble_sort, array, backup, size);
    test_sort_function("Bubble Sort (Recursive)", recursive_bubble_sort, array, backup, size);

 	cout << endl << " ------------------------------------------- " << endl;

	test_sort_function("Gnome Sort", gnome_sort, array, backup, size);

	cout << endl << " ------------------------------------------- " << endl;

	// Order it with cocktail sort
	test_sort_function("Cocktail Sort", cocktail_sort, array, backup, size);
	test_sort_function("Cocktail Sort (Recursive)", cocktail_sort, array, backup, size);

    cout << endl << " ------------------------------------------- " << endl;

    // Order it with selection sort
    test_sort_function("Selection Sort", selection_sort, array, backup, size);
    test_sort_function("Selection Sort (Recursive)", recursive_selection_sort, array, backup, size);
    test_sort_function("Selection Sort (using max)", selection_sort_using_max, array, backup, size);
    test_sort_function("Selection Sort (using max) (Recursive)", recursive_selection_sort_using_max, array, backup, size);

    cout << endl << " ------------------------------------------- " << endl;

	test_sort_function("Insertion Sort", insertion_sort, array, backup, size);
	test_sort_function("Recursive Insertion Sort", recursive_insertion_sort, array, backup, size);

    cout << endl << " ------------------------------------------- " << endl;

	test_sort_function("Shell Sort", shell_sort, array, backup, size);

	cout << endl << " ------------------------------------------- " << endl;

	test_sort_function("Merge Sort (Recursive)", recursive_merge_sort, array, backup, size);
    return 0;
}

// Use pointers to functions to test functions easily.
void test_sort_function(const char* name, sort_function_p sort_function, double array[], double backup[], unsigned int size) {
    unsigned int steps = 0;
    reset_conditions(array, backup, size);
    cout << "Sorted with " << name << ":" << endl;
    steps = sort_function(array, size);
    print_array(array, size);
    cout << endl;
    cout << "steps taken to sort: " << steps << endl;
}


void print_array(double array[], unsigned int size) {
    for (unsigned int i=0; i<size; i++) {
        cout << array[i] << " ";
    }
}

void copy_array_into(double array[], double destination[], unsigned int size) {
    for (unsigned int i=0; i<size; i++) {
        destination[i] = array[i];
    }
}

void reset_conditions(double array[], double backup[], unsigned int size) {
    cout << endl;
    copy_array_into(backup, array, size);
}