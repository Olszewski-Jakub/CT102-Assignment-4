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

void mergeSort(int nums[], int size, int *swaps, int *comparisons, int *functionCalls) {
    *swaps = 0;
    *comparisons = 0;
    *functionCalls = 1;
//    mergeSortRecursive(nums, 0, size - 1, swaps, comparisons, functionCalls);
}

void mergeSortRecursive(int nums[], int lb, int ub, int *swaps, int *comparisons, int *functionCalls) {
    if (lb < ub) { // If the lower bound is less than the upper bound
        int mid = (lb + ub) / 2; // Calculate the middle index
        mergeSortRecursive(nums, lb, mid, swaps, comparisons, functionCalls); // Recursively sort the left half
        mergeSortRecursive(nums, mid + 1, ub, swaps, comparisons, functionCalls); // Recursively sort the right half
        merge(nums, lb, mid, ub, swaps, comparisons); // Merge the sorted halves
    }
}

void merge(int arrA[], int lb, int mid, int ub, int *swaps, int *comparisons) {
    int i, j, k;
    int n1 = mid - lb + 1; // Calculate the size of the left half
    int n2 = ub - mid; // Calculate the size of the right half

    int L[n1], R[n2]; // Create temporary arrays for the left and right halves

    for (i = 0; i < n1; i++) // Copy the left half to the temporary array
        L[i] = arrA[lb + i];
    for (j = 0; j < n2; j++) // Copy the right half to the temporary array
        R[j] = arrA[mid + 1 + j];

    i = 0; // Initialize the index of the left half
    j = 0; // Initialize the index of the right half
    k = lb; // Initialize the index of the merged array

    while (i < n1 && j < n2) { // While there are elements in both halves
        if (L[i] <=
            R[j]) { // If the current element in the left half is less than or equal to the current element in the right half
            arrA[k] = L[i]; // Copy the current element in the left half to the merged array
            i++; // Move to the next element in the left half
        } else { // If the current element in the right half is less than the current element in the left half
            arrA[k] = R[j]; // Copy the current element in the right half to the merged array
            j++; // Move to the next element in the right half
        }
        k++; // Move to the next position in the merged array
    }

    while (i < n1) { // While there are elements in the left half
        arrA[k] = L[i]; // Copy the remaining elements in the left half to the merged array
        i++; // Move to the next element in the left half
        k++; // Move to the next position in the merged array
    }

    while (j < n2) { // While there are elements in the right half
        arrA[k] = R[j]; // Copy the remaining elements in the right half to the merged array
        j++; // Move to the next element in the right half
    }
}