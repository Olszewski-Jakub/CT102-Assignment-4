
#include "include/SortingResult.h"
#include "include/SortingOperations.h"
#include "include/SortingAlgorithms.h"
#include "include/PlotData.h"
#include "plot/supportLib.h"

#define file1 "C://Users//jolsz//uni//freshman//CT102 - Algorithms & Information Systems//assignmnets//Assignment_4//Sorting_Algorithms_Performance_Analysis//files//file1.txt"
#define file2 "C://Users//jolsz//uni//freshman//CT102 - Algorithms & Information Systems//assignmnets//Assignment_4//Sorting_Algorithms_Performance_Analysis//files//file2.txt"

#define result_file_1 "C://Users//jolsz//uni//freshman//CT102 - Algorithms & Information Systems//assignmnets//Assignment_4//Sorting_Algorithms_Performance_Analysis//files//result_file1.csv"
#define result_file_2 "C://Users//jolsz//uni//freshman//CT102 - Algorithms & Information Systems//assignmnets//Assignment_4//Sorting_Algorithms_Performance_Analysis//files//result_file2.csv"

#define GRAPH_PATH "C://Users//jolsz//uni//freshman//CT102 - Algorithms & Information Systems//assignmnets//Assignment_4//Sorting_Algorithms_Performance_Analysis//graphs"

#define NUM_SORTING_ALGORITHMS 6
#define NUM_RESULTS_PER_ALGORITHM 10


int numbers[10000];

/**
 * Process the file and save the results in a file
 * @param filePath
 * @param resultFilePath
 */
void processFile(const char *filePath, const char *resultFilePath);

void plotData(SortingResult sortingResults[], int size);

double arrayAverage(double *array, int size);



int main() {

    processFile(file1, result_file_1);
//    processFile(file2, result_file_2);
    return 0;
}

void processFile(const char *filePath, const char *resultFilePath) {
    int arrIndex = 0;
    SortingResult sortingResultsFile[NUM_SORTING_ALGORITHMS * NUM_RESULTS_PER_ALGORITHM];

    // Pass the address of arrIndex and sortingResultsFile to the function
    executeSort(numbers, bubbleSort, "Bubble Sort", &arrIndex, sortingResultsFile, filePath);
    executeSort(numbers, selectionSort, "Selection Sort", &arrIndex, sortingResultsFile, filePath);
    executeSort(numbers, insertionSort, "Insertion Sort", &arrIndex, sortingResultsFile, filePath);
    executeSort(numbers, countingSort, "Count Sort", &arrIndex, sortingResultsFile, filePath);
    executeSort(numbers, mergeSort, "Merge Sort", &arrIndex, sortingResultsFile, filePath);
    executeSort(numbers, quickSort, "Quick Sort", &arrIndex, sortingResultsFile, filePath);
    printResults(&arrIndex, sortingResultsFile);
    writeResultsToFile(sortingResultsFile, NUM_SORTING_ALGORITHMS * 10, resultFilePath);
    if (!writeResultsToFile(sortingResultsFile, NUM_SORTING_ALGORITHMS * NUM_RESULTS_PER_ALGORITHM, resultFilePath)) {
        printf("Error writing to file: %s\n", resultFilePath);
    }
    plotData(sortingResultsFile, NUM_SORTING_ALGORITHMS * NUM_RESULTS_PER_ALGORITHM);
}

double arrayAverage(double *array, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    double average = sum / size;
    return average;
}

void plotData(SortingResult sortingResults[], int size) {
    //Split the sortingResults array into 6 arrays, one for each sorting algorithm for timetake, comparisons, swaps, array size and functioncalls
    //Make for xasmple 2d aray fo time taken whre each row is a sorting algorithm and each column is a result
    // array shoudle be only for time taken and arraya size is [NUM_SORTING_ALGORITHMS][NUM_RESULTS_PER_ALGORITHM]
    double timeTaken[NUM_SORTING_ALGORITHMS][NUM_RESULTS_PER_ALGORITHM];
    double comparisons[NUM_SORTING_ALGORITHMS][NUM_RESULTS_PER_ALGORITHM];
    double swaps[NUM_SORTING_ALGORITHMS][NUM_RESULTS_PER_ALGORITHM];
    double arraySize[NUM_SORTING_ALGORITHMS][NUM_RESULTS_PER_ALGORITHM];
    double functionCalls[NUM_SORTING_ALGORITHMS][NUM_RESULTS_PER_ALGORITHM];
    char *sortingAlgorithms[NUM_SORTING_ALGORITHMS];
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

    double timeTakenAverage[NUM_SORTING_ALGORITHMS];

    for (int i = 0; i < NUM_SORTING_ALGORITHMS; i++) {
        timeTakenAverage[i] = arrayAverage(timeTaken[i], NUM_RESULTS_PER_ALGORITHM);
    }
    // Convert time taken average to milliseconds
    for (int i = 0; i < NUM_SORTING_ALGORITHMS; i++) {
        timeTakenAverage[i] = timeTakenAverage[i] * 1000;
    }
    drawAvgTimeVsAlg(timeTakenAverage, NUM_SORTING_ALGORITHMS,
                     "Average Time Taken vs Sorting Algorithm", "Time Taken (ms)", sortingAlgorithms, GRAPH_PATH);


    //Draw sctter plot comparing comparisons vs time taken for each sorting algorithm
    double timeTakenAll[NUM_SORTING_ALGORITHMS * NUM_RESULTS_PER_ALGORITHM];
    double comparisonsAll[NUM_SORTING_ALGORITHMS * NUM_RESULTS_PER_ALGORITHM];
    double swapsAll[NUM_SORTING_ALGORITHMS * NUM_RESULTS_PER_ALGORITHM];
    for (int i = 0; i < NUM_SORTING_ALGORITHMS; i++) {
        for (int j = 0; j < NUM_RESULTS_PER_ALGORITHM; j++) {
            timeTakenAll[i * NUM_RESULTS_PER_ALGORITHM + j] = timeTaken[i][j];
            comparisonsAll[i * NUM_RESULTS_PER_ALGORITHM + j] = comparisons[i][j];
        }
    }

    for (int i = 0; i < NUM_SORTING_ALGORITHMS; i++) {
        int algorithmIndex = i;
        int resultIndex = i % 6;
        for (int j = 0; j < NUM_RESULTS_PER_ALGORITHM; j++) {

            timeTakenAll[i * NUM_RESULTS_PER_ALGORITHM + j] = timeTaken[algorithmIndex][j];
            comparisonsAll[i * NUM_RESULTS_PER_ALGORITHM + j] = comparisons[algorithmIndex][j] / 1000000;
            swapsAll[i * NUM_RESULTS_PER_ALGORITHM + j] = swaps[algorithmIndex][j] /1000000;
        }
    }


    plotAndAnalyzeDataPoints(comparisonsAll, timeTakenAll, NUM_SORTING_ALGORITHMS * NUM_RESULTS_PER_ALGORITHM,
                             GRAPH_PATH,"comp_vs_time.png", "Comparisons vs Time Taken)", "Time taken (ms)", "Comparisons (Millions)");

    //Draw sctter plot comparing swaps vs time taken for each sorting algorithm
    plotAndAnalyzeDataPoints(swapsAll, timeTakenAll, NUM_SORTING_ALGORITHMS * NUM_RESULTS_PER_ALGORITHM,
                             GRAPH_PATH,"swaps_vs_time.png", "Swaps vs Time Taken", "Time taken (ms)", "Swaps (Millions)");
}

