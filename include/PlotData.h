//
// Created by jolsz on 13.03.2024.
//

#ifndef QUESTION3_PLOTDATA_H
#define QUESTION3_PLOTDATA_H

#include "../plot/pbPlots.h"
#include "../plot/supportLib.h"
#include "DataAnalysis.h"
#include "CharOperations.h"
#include <malloc.h>


void drawAvgTimeVsAlg(double *avgTime, int size, char *title, char *yLabel, char *xLabel[], char *GRAPH_PATH);

        wchar_t *ConvertToWString(const char *str);

BarPlotSeries *createBarPlotSeries(double *avgTime, size_t length, RGBA *color);

ScatterPlotSeries *createScatterPlotSeries(double *x, double *y, int size, RGBA *color, int interpolationType, int lineType);
void plotAndAnalyzeDataPoints(double xAxis[], double yAxis[], int size, const char *graphPath,const char *fileName, const char *title, const char *yLabel, const char *xLabel);

#endif //QUESTION3_PLOTDATA_H
