#ifndef TIZIOS_SORTING_LIB_TIZIOS_SORTING_H
#define TIZIOS_SORTING_LIB_TIZIOS_SORTING_H

// Support functions
void swap(double& n, double& m);

// The best sorting algorithm overall
unsigned int bogo_sort(double *arr, unsigned int size);

/* SIMPLE SORTING ALGORITHMS */
// Bubble sort
unsigned int bubble_sort(double *arr, unsigned int size);
unsigned int recursive_bubble_sort(double *arr, unsigned int size);

// Selection sort
unsigned int selection_sort(double *arr, int size);
unsigned int recursive_selection_sort(double *arr, int size);

// Insertion sort
unsigned int insertion_sort(double *arr, int size);
unsigned int recursive_insertion_sort(double *arr, int size);

// Gnome sort
unsigned int gnome_sort(double *arr, int size);
unsigned int recursive_gnome_sort(double *arr, int size);

// Cocktail sort
unsigned int cocktail_sort(double *arr, int size);
unsigned int recursive_cocktail_sort(double *arr, int size);

/* ADVANCED SORTING ALGORITHMS */
// Merge sort
unsigned int merge_sort(double *arr, int size);
unsigned int recursive_merge_sort(double *arr, int size);

// Quick sort
unsigned int quick_sort(double *arr, int size);
unsigned int recursive_quick_sort(double *arr, int size);

// Heap sort
unsigned int heap_sort(double *arr, int size);
unsigned int recursive_heap_sort(double *arr, int size);

/* NON-COMPARISON SORTS */
// Counting sort
unsigned int counting_sort(double *arr, int size);
unsigned int recursive_counting_sort(double *arr, int size);

// Radix sort
unsigned int radix_sort(double *arr, int size);
unsigned int recursive_radix_sort(double *arr, int size);

// Bucket sort
unsigned int bucket_sort(double *arr, int size);
unsigned int recursive_bucket_sort(double *arr, int size);

/* OTHER */
// Shell sort
unsigned int shell_sort(double *arr, int size);
unsigned int recursive_shell_sort(double *arr, int size);

// Comb sort
unsigned int comb_sort(double *arr, int size);
unsigned int recursive_comb_sort(double *arr, int size);

#endif //TIZIOS_SORTING_LIB_TIZIOS_SORTING_H