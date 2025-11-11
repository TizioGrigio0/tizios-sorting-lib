#ifndef TIZIOS_SORTING_LIB_TIZIOS_SORTING_H
#define TIZIOS_SORTING_LIB_TIZIOS_SORTING_H

// Declare the typedef for the pointer to function "sort_function_p"
typedef unsigned int (*sort_function_p)(double[], unsigned int);

// Support functions
unsigned int swap(double& n, double& m);

// The best sorting algorithm overall
unsigned int bogo_sort(double *arr, unsigned int size);

/* SIMPLE SORTING ALGORITHMS */
// Bubble sort
unsigned int bubble_sort(double *arr, unsigned int size);
unsigned int recursive_bubble_sort(double *arr, unsigned int size);

// Selection sort
unsigned int selection_sort(double *arr, unsigned int size);
unsigned int recursive_selection_sort(double *arr, unsigned int size);
unsigned int selection_sort_using_max(double *arr, unsigned int size);
unsigned int recursive_selection_sort_using_max(double *arr, unsigned int size);

/*
// Insertion sort // TODO
unsigned int insertion_sort(double *arr, unsigned int size);
unsigned int recursive_insertion_sort(double *arr, unsigned int size);

// Gnome sort // TODO
unsigned int gnome_sort(double *arr, unsigned int size);
unsigned int recursive_gnome_sort(double *arr, unsigned int size);

// Cocktail sort // TODO
unsigned int cocktail_sort(double *arr, unsigned int size);
unsigned int recursive_cocktail_sort(double *arr, unsigned int size);
*/
/* ADVANCED SORTING ALGORITHMS */
/*
// Merge sort // TODO
unsigned int merge_sort(double *arr, unsigned int size);
unsigned int recursive_merge_sort(double *arr, unsigned int size);

// Quick sort // TODO
unsigned int quick_sort(double *arr, unsigned int size);
unsigned int recursive_quick_sort(double *arr, unsigned int size);

// Heap sort // TODO
unsigned int heap_sort(double *arr, unsigned int size);
unsigned int recursive_heap_sort(double *arr, unsigned int size);
*/
/* NON-COMPARISON SORTS */
/*
// Counting sort // TODO
unsigned int counting_sort(double *arr, unsigned int size);
unsigned int recursive_counting_sort(double *arr, unsigned int size);

// Radix sort // TODO
unsigned int radix_sort(double *arr, unsigned int size);
unsigned int recursive_radix_sort(double *arr, unsigned int size);

// Bucket sort // TODO
unsigned int bucket_sort(double *arr, unsigned int size);
unsigned int recursive_bucket_sort(double *arr, unsigned int size);
*/
/* OTHER */
/*
// Shell sort // TODO
unsigned int shell_sort(double *arr, unsigned int size);
unsigned int recursive_shell_sort(double *arr, unsigned int size);

// Comb sort // TODO
unsigned int comb_sort(double *arr, unsigned int size);
unsigned int recursive_comb_sort(double *arr, unsigned int size);
*/
#endif //TIZIOS_SORTING_LIB_TIZIOS_SORTING_H