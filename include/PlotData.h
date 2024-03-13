//
// Created by jolsz on 13.03.2024.
//

#ifndef QUESTION3_PLOTDATA_H
#define QUESTION3_PLOTDATA_H

#include "../pbPlot//pbPlots.h"
#include "../pbPlot/supportLib.h"
#include "DataAnalysis.h"
#include "CharOperations.h"
#include <malloc.h>


/**
 * @brief Draws a bar pbPlot of average time versus algorithm.
 *
 * This function takes five parameters: a pointer to a double array representing the average time, an integer representing the size of the array, two character pointers representing the title and y-axis label of the pbPlot, and a character pointer representing the path to save the graph.
 *
 * @param avgTime A pointer to a double array representing the average time.
 * @param size The size of the array.
 * @param title The title of the pbPlot.
 * @param yLabel The y-axis label of the pbPlot.
 * @param xLabel An array of labels for the x-axis.
 * @param GRAPH_PATH The path to save the graph.
 * @param fileName The file name.
 */
void drawAvgTimeVsAlg(double *avgTime, int size, char *title, char *yLabel, char *xLabel[], char *GRAPH_PATH,char *fileName);

/**
 * @brief Converts a character array to a wide character array.
 *
 * This function takes a constant character pointer as input and returns a pointer to a wide character array.
 *
 * @param str The character array to convert.
 * @return A pointer to the converted wide character array.
 */
wchar_t *ConvertToWString(const char *str);

/**
 * @brief Creates a bar pbPlot series.
 *
 * This function takes three parameters: a pointer to a double array representing the average time, a size_t representing the length of the array, and a pointer to an RGBA structure representing the color of the bars.
 *
 * @param avgTime A pointer to a double array representing the average time.
 * @param length The length of the array.
 * @param color A pointer to an RGBA structure representing the color of the bars.
 * @return A pointer to the created BarPlotSeries.
 */
BarPlotSeries *createBarPlotSeries(double *avgTime, size_t length, RGBA *color);

/**
 * @brief Creates a scatter pbPlot series.
 *
 * This function takes six parameters: two pointers to double arrays representing the x and y coordinates of the points, an integer representing the size of the arrays, a pointer to an RGBA structure representing the color of the points, and two integers representing the interpolation type and line type.
 *
 * @param x A pointer to a double array representing the x coordinates of the points.
 * @param y A pointer to a double array representing the y coordinates of the points.
 * @param size The size of the arrays.
 * @param color A pointer to an RGBA structure representing the color of the points.
 * @param interpolationType The interpolation type.
 * @param lineType The line type.
 * @return A pointer to the created ScatterPlotSeries.
 */
ScatterPlotSeries *createScatterPlotSeries(double *x, double *y, int size, RGBA *color, int interpolationType, int lineType);

/**
 * @brief Plots and analyzes data points.
 *
 * This function takes eight parameters: two pointers to double arrays representing the x and y coordinates of the points, an integer representing the size of the arrays, and five character pointers representing the path to save the graph, the file name, the title of the pbPlot, and the labels of the y and x axes.
 *
 * @param xAxis A pointer to a double array representing the x coordinates of the points.
 * @param yAxis A pointer to a double array representing the y coordinates of the points.
 * @param size The size of the arrays.
 * @param graphPath The path to save the graph.
 * @param fileName The file name.
 * @param title The title of the pbPlot.
 * @param yLabel The y-axis label of the pbPlot.
 * @param xLabel The x-axis label of the pbPlot.
 */
void plotAndAnalyzeDataPoints(double xAxis[], double yAxis[], int size, const char *graphPath, const char *fileName,
                              const char *title, const char *yLabel, const char *xLabel);

#endif //QUESTION3_PLOTDATA_H
