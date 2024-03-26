
#include "include/SortingResult.h"
#include "include/SortingOperations.h"
#include "include/SortingAlgorithms.h"
#include "include/PlotData.h"


#define file1 "./files/dataset/file1.txt"
#define file2 "C://Users//jolsz//uni//freshman//CT102 - Algorithms & Information Systems//assignmnets//Assignment_4//Sorting_Algorithms_Performance_Analysis//files//file2.txt"

#define result_file_1 "./files/result/result_file1.csv"
#define result_file_2 "C://Users//jolsz//uni//freshman//CT102 - Algorithms & Information Systems//assignmnets//Assignment_4//Sorting_Algorithms_Performance_Analysis//files//result_file2.csv"

#define GRAPH_PATH "./graphs"

#define NUM_SORTING_ALGORITHMS 6
#define NUM_RESULTS_PER_ALGORITHM 10


int numbers[10000];

/**
 * Process the file and save the results in a file
 * @param filePath
 * @param resultFilePath
 */
void processFile(const char *filePath, const char *resultFilePath, int *fileExecutionCount);

void plotData(SortingResult sortingResults[], int size, int numSortingAlgorithms, int resultPerAlgorithm, int *fileExecutionCount);


void executeSortingAlgorithms(int *numbers, int *arrIndex, SortingResult *sortingResultsFile, const char *filePath);

int main() {
    int fileExecutionCount = 0;
    processFile(file1, result_file_1, &fileExecutionCount);
//    processFile(file2, result_file_2, &fileExecutionCount);
    return 0;
}


void processFile(const char *filePath, const char *resultFilePath, int *fileExecutionCount) {
    (*fileExecutionCount)++;
    int arrIndex = 0;
    int arrSize = NUM_SORTING_ALGORITHMS * NUM_RESULTS_PER_ALGORITHM;
    SortingResult sortingResultsFile[NUM_SORTING_ALGORITHMS * NUM_RESULTS_PER_ALGORITHM];

    // Pass the address of arrIndex and sortingResultsFile to the function
    executeSortingAlgorithms(numbers, &arrIndex, sortingResultsFile, filePath);
    printResults(&arrIndex, sortingResultsFile);
    writeResultsToFile(sortingResultsFile, NUM_SORTING_ALGORITHMS * 10, resultFilePath);
    if (!writeResultsToFile(sortingResultsFile, arrSize, resultFilePath)) {
        printf("Error writing to file: %s\n", resultFilePath);
    }
    plotData(sortingResultsFile, arrSize,NUM_SORTING_ALGORITHMS,NUM_RESULTS_PER_ALGORITHM, fileExecutionCount);
}

void plotData(SortingResult sortingResults[], int size, int numSortingAlgorithms, int resultPerAlgorithm, int *fileExecutionCount) {


    double timeTaken[numSortingAlgorithms][resultPerAlgorithm];
    double comparisons[numSortingAlgorithms][resultPerAlgorithm];
    double swaps[numSortingAlgorithms][resultPerAlgorithm];
    double arraySize[numSortingAlgorithms][resultPerAlgorithm];
    double functionCalls[numSortingAlgorithms][resultPerAlgorithm];
    char *sortingAlgorithms[numSortingAlgorithms];
    for (int i = 0; i < size; i++) {
        int algorithmIndex = i / 10;
        int resultIndex = i % 10;
        timeTaken[algorithmIndex][resultIndex] = sortingResults[i].timeTaken;
        comparisons[algorithmIndex][resultIndex] = sortingResults[i].comparisons;
        swaps[algorithmIndex][resultIndex] = sortingResults[i].swaps;
        arraySize[algorithmIndex][resultIndex] = sortingResults[i].size;
        functionCalls[algorithmIndex][resultIndex] = sortingResults[i].functionCalls;
        sortingAlgorithms[algorithmIndex] = sortingResults[i].sortingAlgorithm;
    }

    double timeTakenAverage[numSortingAlgorithms];

    for (int i = 0; i < numSortingAlgorithms; i++) {
        timeTakenAverage[i] = arrayAverage(timeTaken[i], resultPerAlgorithm);
    }
    // Convert time taken average to milliseconds
    for (int i = 0; i < numSortingAlgorithms; i++) {
        timeTakenAverage[i] = timeTakenAverage[i] * 1000;
    }

    double timeTakenAll[size];
    double comparisonsAll[size];
    double swapsAll[size];
    for (int i = 0; i < numSortingAlgorithms; i++) {
        for (int j = 0; j < resultPerAlgorithm; j++) {
            timeTakenAll[i * resultPerAlgorithm + j] = timeTaken[i][j];
            comparisonsAll[i * resultPerAlgorithm + j] = comparisons[i][j];
        }
    }

    for (int i = 0; i < numSortingAlgorithms; i++) {
        int algorithmIndex = i;
        for (int j = 0; j < resultPerAlgorithm; j++) {
            timeTakenAll[i * resultPerAlgorithm + j] = timeTaken[algorithmIndex][j];
            comparisonsAll[i * resultPerAlgorithm + j] = comparisons[algorithmIndex][j] / 1000000;
            swapsAll[i * resultPerAlgorithm + j] = swaps[algorithmIndex][j] / 1000000;
        }
    }
    drawAvgTimeVsAlg(timeTakenAverage, numSortingAlgorithms,
                     "Average Time Taken vs Sorting Algorithm", "Time Taken (ms)", sortingAlgorithms, GRAPH_PATH,
                     constructFileName("avg_vs_time_file", *fileExecutionCount));

    plotAndAnalyzeDataPoints(comparisonsAll, timeTakenAll, size,
                             GRAPH_PATH, constructFileName("comp_vs_time", *fileExecutionCount),
                             "Comparisons vs Time Taken)", "Time taken (ms)", "Comparisons (Millions)");

    plotAndAnalyzeDataPoints(swapsAll, timeTakenAll, size,
                             GRAPH_PATH, constructFileName("swaps_vs_time", *fileExecutionCount), "Swaps vs Time Taken",
                             "Time taken (ms)", "Swaps (Millions)");
}

void executeSortingAlgorithms(int *numbers, int *arrIndex, SortingResult *sortingResultsFile, const char *filePath) {
    executeSort(numbers, bubbleSort, "Bubble Sort", arrIndex, sortingResultsFile, filePath);
    executeSort(numbers, selectionSort, "Selection Sort", arrIndex, sortingResultsFile, filePath);
    executeSort(numbers, insertionSort, "Insertion Sort", arrIndex, sortingResultsFile, filePath);
    executeSort(numbers, countingSort, "Count Sort", arrIndex, sortingResultsFile, filePath);
    executeSort(numbers, mergeSort, "Merge Sort", arrIndex, sortingResultsFile, filePath);
    executeSort(numbers, quickSort, "Quick Sort", arrIndex, sortingResultsFile, filePath);
}
