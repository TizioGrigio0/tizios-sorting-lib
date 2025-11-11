#include <iostream>
#include "tizios-sorting.h"

using namespace std;

void print_array(double[], unsigned int);
void copy_array_into(double[], double[], unsigned int);

int main(int argc, char *argv[]) {

    // Missing arguments error message
    if (argc < 2) {
        cout << "Missing arguments, input at least 2 elements for the array." << endl;
        return 1;
    }

    // Set up the original array
    unsigned int size = argc - 1;
    double array[argc-1] = {};
    double backupArray[argc-1] = {}; // used to reset the ordered array to the original state

    for (int i=1; i<argc; i++) {
        array[i-1] = atof(argv[i]);
        backupArray[i-1] = array[i-1];
    }

    // Print the original array
    cout << "Original array:" << endl;
    print_array(array, size);
    cout << endl;

    unsigned int steps = 0;
    cout << endl;

    // Order it with bubble sort
    cout << "Sorted with 'bubble sort':" << endl;
    steps = bubble_sort(array, size);
    print_array(array, size);
    cout << endl;
    cout << "steps taken to sort: " << steps << endl;

    cout << endl;
    copy_array_into(backupArray, array, size);

    // Order it with recursive bubble sort
    cout << "Recursive bubble sort approach:" << endl;
    steps = recursive_bubble_sort(array, size);
    print_array(array, size);
    cout << endl;
    cout << "steps taken to sort: " << steps << endl;

    cout << endl;
    copy_array_into(backupArray, array, size);

    // Order it with selection sort
    cout << "Sorted with 'selection sort':" << endl;
    steps = selection_sort(array, size);
    print_array(array, size);
    cout << endl;
    cout << "steps taken to sort: " << steps << endl;

    cout << endl;
    copy_array_into(backupArray, array, size);

    cout << "Recursive selection sort approach:" << endl;
    steps = recursive_selection_sort(array, size);
    print_array(array, size);
    cout << endl;
    cout << "steps taken to sort: " << steps << endl;

    return 0;
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