#ifndef QUESTION3_SORTINGALGORITHMS_H
#define QUESTION3_SORTINGALGORITHMS_H

#include <stdio.h>
#include <stdlib.h>
#include "Swap.h"


/**
 * Sorts an array of integers using the bubble sort algorithm.
 *
 * @param nums The array to be sorted.
 * @param size The size of the array.
 * @param swaps A pointer to an integer where the number of swaps will be stored.
 * @param comparisons A pointer to an integer where the number of comparisons will be stored.
 * @param functionCalls A pointer to an integer where the number of function calls will be stored.
 */
void bubbleSort(int nums[], int size, int *swaps, int *comparisons, int *functionCalls);

/**
 * Sorts an array of integers using the selection sort algorithm.
 *
 * @param nums The array to be sorted.
 * @param size The size of the array.
 * @param swaps A pointer to an integer where the number of swaps will be stored.
 * @param comparisons A pointer to an integer where the number of comparisons will be stored.
 * @param functionCalls A pointer to an integer where the number of function calls will be stored.
 */
void selectionSort(int nums[], int size, int *swaps, int *comparisons, int *functionCalls);

/**
 * Sorts an array of integers using the insertion sort algorithm.
 *
 * @param nums The array to be sorted.
 * @param size The size of the array.
 * @param swaps A pointer to an integer where the number of swaps will be stored.
 * @param comparisons A pointer to an integer where the number of comparisons will be stored.
 * @param functionCalls A pointer to an integer where the number of function calls will be stored.
 */
void insertionSort(int nums[], int size, int *swaps, int *comparisons, int *functionCalls);

/**
 * Sorts an array of integers using the counting sort algorithm.
 *
 * @param nums The array to be sorted.
 * @param size The size of the array.
 * @param swaps A pointer to an integer where the number of swaps will be stored.
 * @param comparisons A pointer to an integer where the number of comparisons will be stored.
 * @param functionCalls A pointer to an integer where the number of function calls will be stored.
 */
void countingSort(int nums[], int size, int *swaps, int *comparisons, int *functionCalls);

/**
 * Sorts an array of integers using the merge sort algorithm.
 *
 * @param nums The array to be sorted.
 * @param size The size of the array.
 * @param swaps A pointer to an integer where the number of swaps will be stored.
 * @param comparisons A pointer to an integer where the number of comparisons will be stored.
 * @param functionCalls A pointer to an integer where the number of function calls will be stored.
 */
void mergeSort(int nums[], int size, int *swaps, int *comparisons, int *functionCalls);

/**
 * Recursively sorts an array of integers using the merge sort algorithm.
 *
 * @param nums The array to be sorted.
 * @param lb The lower bound of the section of the array to be sorted.
 * @param ub The upper bound of the section of the array to be sorted.
 * @param swaps A pointer to an integer where the number of swaps will be stored.
 * @param comparisons A pointer to an integer where the number of comparisons will be stored.
 * @param functionCalls A pointer to an integer where the number of function calls will be stored.
 */
void mergeSortRecursive(int nums[], int lb, int ub, int *swaps, int *comparisons, int *functionCalls);

/**
 * Merges two sorted sections of an array into a single sorted section.
 *
 * @param arrA The array containing the sections to be merged.
 * @param lb The lower bound of the first section to be merged.
 * @param mid The upper bound of the first section and lower bound of the second section to be merged.
 * @param ub The upper bound of the second section to be merged.
 * @param swaps A pointer to an integer where the number of swaps will be stored.
 * @param comparisons A pointer to an integer where the number of comparisons will be stored.
 */
void merge(int arrA[], int lb, int mid, int ub, int *swaps, int *comparisons, int *functionCalls);

/**
 * @brief Sorts an array of integers using the quick sort algorithm.
 *
 * This function takes five parameters: an array of integers to be sorted, the size of the array, and three pointers to integers where the number of swaps, comparisons, and function calls will be stored.
 *
 * @param nums The array to be sorted.
 * @param size The size of the array.
 * @param swaps A pointer to an integer where the number of swaps will be stored.
 * @param comparisons A pointer to an integer where the number of comparisons will be stored.
 * @param functionCalls A pointer to an integer where the number of function calls will be stored.
 */
void quickSort(int nums[], int size, int *swaps, int *comparisons, int *functionCalls);

/**
 * @brief Recursively sorts an array of integers using the quick sort algorithm.
 *
 * This function takes six parameters: an array of integers to be sorted, the start and end indices of the section of the array to be sorted, and three pointers to integers where the number of swaps, comparisons, and function calls will be stored.
 *
 * @param arrA The array to be sorted.
 * @param startval The start index of the section of the array to be sorted.
 * @param endval The end index of the section of the array to be sorted.
 * @param swaps A pointer to an integer where the number of swaps will be stored.
 * @param comparisons A pointer to an integer where the number of comparisons will be stored.
 * @param functionCalls A pointer to an integer where the number of function calls will be stored.
 */
void quickSortRecursive(int arrA[], int startval, int endval, int *swaps, int *comparisons, int *functionCalls);

/**
 * @brief Partitions an array for the quick sort algorithm.
 *
 * This function takes six parameters: an array of integers to be partitioned, the start and end indices of the section of the array to be partitioned, and three pointers to integers where the number of swaps, comparisons, and function calls will be stored.
 *
 * @param arrA The array to be partitioned.
 * @param startval The start index of the section of the array to be partitioned.
 * @param endval The end index of the section of the array to be partitioned.
 * @param swaps A pointer to an integer where the number of swaps will be stored.
 * @param comparisons A pointer to an integer where the number of comparisons will be stored.
 * @param functionCalls A pointer to an integer where the number of function calls will be stored.
 * @return The pivot index after partitioning.
 */
int partition(int arrA[], int startval, int endval, int *swaps, int *comparisons, int *functionCalls);

#endif //QUESTION3_SORTINGALGORITHMS_H