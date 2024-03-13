//
// Created by jolsz on 13.03.2024.
//

#ifndef QUESTION3_PLOTDATA_H
#define QUESTION3_PLOTDATA_H

#include "../plot/pbPlots.h"
#include "../plot/supportLib.h"
#include "CharOperations.h"
#include <malloc.h>

void drawAvgTimeVsAlg(double *avgTime, int size, char *title, char *yLabel, char *xLabel[], char *GRAPH_PATH);

        wchar_t *ConvertToWString(const char *str);

BarPlotSeries *createBarPlotSeries(double *avgTime, size_t length, RGBA *color);

ScatterPlotSeries *createScatterPlotSeries(double *x, double *y, int size, RGBA *color);

void drawCompVsTimeTaken(double comparisons[], double timeTaken[], int size, const char *graphPath);

#endif //QUESTION3_PLOTDATA_H
