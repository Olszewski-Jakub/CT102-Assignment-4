#include "../include/SortingAlgorithms.h"


// Bubble Sort function
void bubbleSort(int nums[], int size, int *swaps, int *comparisons, int *functionCalls) {
    *swaps = 0;
    *comparisons = 0;
    *functionCalls = 1;

    for (int i = 0; i < size - 1; i++) { // Iterate over each element in the array
        for (int j = 0;
             j < size - i - 1; j++) { // For each element, iterate over the array again, excluding the last i elements
            (*comparisons)++; // Increment the comparison count
            if (nums[j] > nums[j + 1]) { // If the current element is greater than the next one
                swap(&nums[j], &nums[j + 1]); // Swap the current element with the next one
                (*swaps)++; // Increment the swap count
            }
        }
    }
}

void selectionSort(int nums[], int size, int *swaps, int *comparisons, int *functionCalls) {
    *swaps = 0;
    *comparisons = 0;
    *functionCalls = 1;
    for (int step = 0; step < size - 1; step++) { // Iterate over each element in the array
        int min_idx = step; // Assume the current element is the smallest
        for (int i = step + 1; i < size; i++) { // For each element, iterate over the rest of the array
            (*comparisons)++; // Increment the comparison count
            if (nums[i] < nums[min_idx]) { // If a smaller element is found
                min_idx = i; // Update the index of the smallest element
            }
        }

        // After finding the smallest element in the unsorted part of the array
        (*swaps)++; // Increment the swap count
        swap(&nums[min_idx], &nums[step]); // Swap the smallest element with the first element of the unsorted part
    }
}

void insertionSort(int nums[], int size, int *swaps, int *comparisons, int *functionCalls) {

    *swaps = 0;
    *comparisons = 0;
    *functionCalls = 1;

    int i, j, current;
    for (i = 0; i < size; i++) { // Iterate over each element in the array
        current = nums[i]; // Store the current element
        for (j = i - 1; j >= 0 && current < nums[j]; j--) { // Iterate backwards from the current element
            nums[j + 1] = nums[j]; // Shift the elements to the right
            (*swaps)++; // Increment the swap count
            (*comparisons)++; // Increment the comparison count
        }
        if (i != j + 1) { // If the current element has been moved
            nums[j + 1] = current; // Insert the current element in its correct position
            (*swaps)++; // Increment the swap count
        }
    }
}

void countingSort(int nums[], int size, int *swaps, int *comparisons, int *functionCalls) {
    *swaps = 0;
    *comparisons = 0; // Counting Sort doesn't involve comparisons
    *functionCalls = 1;

    int max = nums[0]; // Initialize max with the first element of the array
    int min = nums[0]; // Initialize min with the first element of the array
    for (int i = 1; i < size; ++i) { // Iterate over the array starting from the second element
        (*comparisons)++; // Increment the comparison count
        if (nums[i] > max) { // If the current element is greater than max
            max = nums[i]; // Update max
            (*swaps)++; // Increment the swap count
        }
        (*comparisons)++; // Increment the comparison count

        if (nums[i] < min) { // If the current element is less than min
            min = nums[i]; // Update min
            (*swaps)++; // Increment the swap count
        }
    }

    // Calculate the range of the count array
    int range = max - min + 1; // The range is the difference between max and min plus 1

    // Allocate memory for count array
    int *count = (int *) malloc(
            range * sizeof(int)); // Allocate memory for the count array with size equal to the range
    // Allocate memory for output array
    int *output = (int *) malloc(
            size * sizeof(int)); // Allocate memory for the output array with size equal to the size of the input array
    if (count == NULL || output == NULL) { // If memory allocation failed for either of the arrays
        printf("Memory allocation failed.\n"); // Print an error message
        return; // Exit the function
    }

    // Initialize count array with all zeros
    for (int i = 0; i < range; ++i) // Iterate over the count array
        count[i] = 0; // Set each element to 0

    // Store the count of each element in count array
    for (int i = 0; i < size; ++i) // Iterate over the input array
        ++count[nums[i] - min]; // Increment the count of the current element in the count array

    // Store the cumulative count of each array
    for (int i = 1; i < range; ++i) // Iterate over the count array starting from the second element
        count[i] += count[i - 1]; // Add the count of the previous element to the current element

    // Build the output array
    for (int i = size - 1; i >= 0; --i) { // Iterate over the input array in reverse order
        output[count[nums[i] - min] -
               1] = nums[i]; // Place the current element in its sorted position in the output array
        --count[nums[i] - min]; // Decrement the count of the current element in the count array
    }

    // Copy the sorted elements back into original array
    for (int i = 0; i < size; ++i) // Iterate over the output array
        nums[i] = output[i]; // Copy each element to the input array

    // Free dynamically allocated memory
    free(count); // Free the memory allocated for the count array
    free(output); // Free the memory allocated for the output array
}

// Merge Sort function
void mergeSort(int nums[], int size, int *swaps, int *comparisons, int *functionCalls) {
    // Initialize counters
    *swaps = 0;
    *comparisons = 0;
    *functionCalls = 0;
    // Call the recursive merge sort function
    mergeSortRecursive(nums, 0, size - 1, swaps, comparisons, functionCalls);
}

// Recursive function for Merge Sort
void mergeSortRecursive(int arrA[], int lb, int ub, int *swaps, int *comparisons, int *functionCalls) {
    // Increment function call count
    (*functionCalls)++;
    int mid;
    // If lower bound is less than upper bound
    if (lb < ub) {
        // Calculate mid point
        mid = (lb + ub) / 2;
        // Recursively sort first half
        mergeSortRecursive(arrA, lb, mid, swaps, comparisons, functionCalls);
        // Recursively sort second half
        mergeSortRecursive(arrA, mid + 1, ub, swaps, comparisons, functionCalls);
        // Merge the two halves
        merge(arrA, lb, mid, ub, swaps, comparisons, functionCalls);
    }
}

// Merge function for Merge Sort
void merge(int arrA[], int lb, int mid, int ub, int *swaps, int *comparisons, int *functionCalls) {
    // Increment the function call count
    (*functionCalls)++;
    int i, j, k;
    // Calculate size of the array to be merged
    int size = ub - lb + 1;
    // Allocate memory for temporary array
    int *arrC = (int *) calloc(size, sizeof(int));
    // Initialize indices
    i = lb;
    j = mid + 1;
    k = 0;
    // Merge the two halves into temporary array
    while (i <= mid && j <= ub) {
        (*comparisons)++;
        if (arrA[i] <= arrA[j]) {
            arrC[k] = arrA[i];
            i++;
        } else {
            arrC[k] = arrA[j];
            j++;
        }
        k++;
        (*swaps)++;
    }
    // Copy remaining elements from first half, if any
    while (i <= mid) {
        arrC[k] = arrA[i];
        i++;
        k++;
        (*swaps)++;
    }
    // Copy remaining elements from second half, if any
    while (j <= ub) {
        arrC[k] = arrA[j];
        j++;
        k++;
        (*swaps)++;
    }
    // Copy sorted array back to original array
    i = lb;
    k = 0;
    while (i <= ub) {
        arrA[i] = arrC[k];
        i++;
        k++;
    }
    // Free dynamically allocated memory
    free(arrC);
}

// Quick Sort function
void quickSort(int nums[], int size, int *swaps, int *comparisons, int *functionCalls) {
    // Initialize counters
    *swaps = 0;
    *comparisons = 0;
    *functionCalls = 0;
    // Call the recursive quick sort function
    quickSortRecursive(nums, 0, size - 1, swaps, comparisons, functionCalls);
}

// Recursive function for Quick Sort
void quickSortRecursive(int arrA[], int startval, int endval, int *swaps, int *comparisons, int *functionCalls) {
    // Increment function call count
    (*functionCalls)++;
    // If there are more than one elements to sort
    if ((endval - startval) >= 1) {
        // Partition the array and get the pivot position
        int k = partition(arrA, startval, endval, swaps, comparisons, functionCalls);
        // Recursively sort elements before pivot
        quickSortRecursive(arrA, startval, k - 1, swaps, comparisons, functionCalls);
        // Recursively sort elements after pivot
        quickSortRecursive(arrA, k + 1, endval, swaps, comparisons, functionCalls);
    }
}

// Partition function for Quick Sort
int partition(int arrA[], int startval, int endval, int *swaps, int *comparisons, int *functionCalls) {
    // Increment function call count
    (*functionCalls)++;
    // Calculate mid point
    int mid = startval + (endval - startval) / 2;
    // Sort start, mid and end elements to find the median
    if (arrA[startval] > arrA[mid]) {
        swap(&arrA[startval], &arrA[mid]);
        (*swaps)++;
    }
    if (arrA[startval] > arrA[endval]) {
        swap(&arrA[startval], &arrA[endval]);
        (*swaps)++;
    }
    if (arrA[mid] > arrA[endval]) {
        swap(&arrA[mid], &arrA[endval]);
        (*swaps)++;
    }
    // Swap mid element with start element
    swap(&arrA[mid], &arrA[startval]);
    (*comparisons) += 3;
    // Choose pivot as start element
    int pivot = arrA[startval];
    int k = startval;
    // Partition the array around pivot
    for (int j = startval + 1; j <= endval; j++) {
        (*comparisons)++;
        if (arrA[j] <= pivot) {
            k++;
            if (k != j) {
                swap(&arrA[k], &arrA[j]);
                (*swaps)++;
            }
        }
    }
    // Swap pivot with element at k
    swap(&arrA[k], &arrA[startval]);
    (*swaps)++;
    // Return pivot position
    return k;
}