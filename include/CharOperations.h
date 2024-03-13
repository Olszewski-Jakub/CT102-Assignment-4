//
// Created by jolsz on 13.03.2024.
//

#ifndef QUESTION3_CHAROPERATIONS_H
#define QUESTION3_CHAROPERATIONS_H

#include "string.h"
#include <malloc.h>

/**
 * @brief Combines two character arrays into one.
 *
 * This function takes two constant character pointers as input, representing two character arrays.
 * It returns a pointer to a new character array that is the result of combining the two input arrays.
 *
 * @param array1 The first character array.
 * @param array2 The second character array.
 * @return A pointer to the combined character array.
 */
char* combineCharArrays(const char* array1, const char* array2);

/**
 * @brief Constructs a filename by appending the file execution count to a base string.
 *
 * This function takes an integer representing the file execution count and returns a string representing the filename.
 *
 * @param fileExecutionCount The file execution count.
 * @param fileName The base string.
 * @return The constructed filename.
 */
char* constructFileName(char *fileName, int fileExecutionCount) ;

#endif //QUESTION3_CHAROPERATIONS_H
