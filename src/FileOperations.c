#include <string.h>
#include "../include/FileOperations.h"


int writeResultsToFile(SortingResult sortingResults[], int size, const char *filePath) {
    FILE *file;
    char *filePathCopy = strdup(filePath);
    while ((file = fopen(filePathCopy, "w")) == NULL) {
        // If the file path is not empty, remove the first character and try again
        if (strlen(filePathCopy) > 1) {
            memmove(filePathCopy, filePathCopy + 1, strlen(filePathCopy));
        } else {
            // If the file path is empty, return an error
            free(filePathCopy);
            printf("Error opening file\n");

            return 0;
        }
    }
    fprintf(file, "Sorting Algorithm, Size, Swaps, Comparisons, Function Calls, Time Taken\n");
    for (int i = 0; i < size; i++) {
        fprintf(file, "%s, %d, %d, %d, %d, %f\n", sortingResults[i].sortingAlgorithm, sortingResults[i].size,
                sortingResults[i].swaps, sortingResults[i].comparisons,sortingResults[i].functionCalls, sortingResults[i].timeTaken);
    }
    fclose(file);
    free(filePathCopy);
    return 1;
}

int readNumbersFromFile(const char *filename, int size, int numbers[]) {
    FILE *file;
    char *filenameCopy = strdup(filename);

    // Try to open the file for reading
    while ((file = fopen(filenameCopy, "r")) == NULL) {
        // If the file path is not empty, remove the first character and try again
        if (strlen(filenameCopy) > 1) {
            memmove(filenameCopy, filenameCopy + 1, strlen(filenameCopy));
        } else {
            // If the file path is empty, return an error
            printf("Error opening file %s\n", filenameCopy);

            free(filenameCopy);
            return -1; // Error opening file
        }
    }

    // Read integers from the file and store them in the array
    for (int i = 0; i < size; i++) {
        if (fscanf(file, "%d", &numbers[i]) == EOF) {
            printf("Error: Insufficient numbers in file.\n");
            fclose(file);
            free(filenameCopy);
            return i; // Return the number of integers read
        }
    }

    // Close the file
    fclose(file);
    free(filenameCopy);
    return size; // Return the size of the array
}