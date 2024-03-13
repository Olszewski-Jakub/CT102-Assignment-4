//
// Created by jolsz on 13.03.2024.
//


#include "../include/CharOperations.h"

#include "stdio.h"
char* combineCharArrays(const char* array1, const char* array2) {
    // Allocate memory for the new array. The size is the sum of the sizes of array1 and array2, plus 1 for the null terminator
    char* combinedArray = malloc(strlen(array1) + strlen(array2) + 3);

    // Copy array1 into the new array
    strcpy(combinedArray, array1);
    strcat(combinedArray, "//");
    // Append array2 to the new array
    strcat(combinedArray, array2);



    // Return the new array
    return combinedArray;
}
