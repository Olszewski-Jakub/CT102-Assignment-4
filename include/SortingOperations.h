#ifndef QUESTION3_SORTINGOPERATIONS_H
#define QUESTION3_SORTINGOPERATIONS_H


#include "FileOperations.h"
#include "SortingResult.h"
#include "ResultManagement.h"

/**
 * @brief Executes a sorting algorithm on an array of integers and records the results.
 *
 * This function takes six parameters: an array of integers to be sorted, a pointer to a sorting function, a string representing the name of the sorting algorithm, a pointer to an integer representing the index of the array, an array of SortingResult structures to store the results, and a string representing the path of the file where the results will be written.
 *
 * @param numbers The array to be sorted.
 * @param sort A pointer to the sorting function to be used.
 * @param algorithmName The name of the sorting algorithm.
 * @param arrIndex A pointer to the index of the array.
 * @param sortingResultsFile An array of SortingResult structures to store the results.
 * @param filePath The path of the file where the results will be written.
 */
void executeSort(int numbers[],void (*sort)(int[], int, int *, int *, int *), char *algorithmName, int *arrIndex,
                 SortingResult sortingResultsFile[], const char *filePath);

/**
 * @brief Checks if an array of integers is sorted in ascending order.
 *
 * This function takes two parameters: an array of integers and the size of the array. It returns 1 if the array is sorted and 0 otherwise.
 *
 * @param arr The array to be checked.
 * @param n The size of the array.
 * @return 1 if the array is sorted, 0 otherwise.
 */
int isSorted(int arr[], int n);

#endif //QUESTION3_SORTINGOPERATIONS_H
