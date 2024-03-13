#ifndef QUESTION3_SORTINGRESULT_H
#define QUESTION3_SORTINGRESULT_H

/**
 * @struct SortingResult
 * @brief A structure that holds the results of a sorting operation.
 *
 * This structure contains five fields: a character array to store the name of the sorting algorithm, four integers to store the size of the array, the number of swaps, comparisons, and function calls made during the sorting operation, and a double to store the time taken for the sorting operation.
 *
 * @var sortingAlgorithm A character array to store the name of the sorting algorithm.
 * @var size An integer to store the size of the array.
 * @var swaps An integer to store the number of swaps made during the sorting operation.
 * @var comparisons An integer to store the number of comparisons made during the sorting operation.
 * @var functionCalls An integer to store the number of function calls made during the sorting operation.
 * @var timeTaken A double to store the time taken for the sorting operation.
 */
typedef struct {
    char sortingAlgorithm[100];
    int size;
    int swaps;
    int comparisons;
    int functionCalls;
    double timeTaken;
} SortingResult;

#endif //QUESTION3_SORTINGRESULT_H
