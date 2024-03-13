//
// Created by jolsz on 13.03.2024.
//

#ifndef QUESTION3_DATAANALYSIS_H
#define QUESTION3_DATAANALYSIS_H

#include "stdlib.h"
#include "stdio.h"

#define MAX_POINTS 10

/**
 * @brief Calculates the slope of a line given a set of points.
 *
 * This function takes three parameters: an integer representing the number of points, and two arrays of doubles representing the x and y coordinates of the points.
 * It returns a double representing the slope of the line that best fits the given points.
 *
 * @param n The number of points.
 * @param x An array of doubles representing the x coordinates of the points.
 * @param y An array of doubles representing the y coordinates of the points.
 * @return The slope of the line.
 */
double calculate_slope(int n, double x[], double y[]);

/**
 * @brief Calculates the y-intercept of a line given a set of points and the slope of the line.
 *
 * This function takes four parameters: an integer representing the number of points, two arrays of doubles representing the x and y coordinates of the points, and a double representing the slope of the line.
 * It returns a double representing the y-intercept of the line that best fits the given points.
 *
 * @param n The number of points.
 * @param x An array of doubles representing the x coordinates of the points.
 * @param y An array of doubles representing the y coordinates of the points.
 * @param slope The slope of the line.
 * @return The y-intercept of the line.
 */
double calculate_intercept(int n, double x[], double y[], double slope);

/**
 * @brief Calculates a set of points on a line given the range of x values, the slope, and the y-intercept.
 *
 * This function takes five parameters: an integer representing the number of points to calculate, two doubles representing the minimum and maximum x values, and two more doubles representing the slope and y-intercept of the line.
 * It returns a pointer to a 2D array of doubles representing the x and y coordinates of the calculated points.
 *
 * @param num_points The number of points to calculate.
 * @param x_min The minimum x value.
 * @param x_max The maximum x value.
 * @param slope The slope of the line.
 * @param intercept The y-intercept of the line.
 * @return A pointer to a 2D array of doubles representing the x and y coordinates of the calculated points.
 */
double **calculate_points_on_line(int num_points, double x_min, double x_max, double slope, double intercept);

/**
 * @brief Calculate the average of an array
 * @param array The array to calculate the average of
 * @param size The size of the array
 * @return The average of the array
 */
double arrayAverage(double *array, int size);

#endif //QUESTION3_DATAANALYSIS_H
