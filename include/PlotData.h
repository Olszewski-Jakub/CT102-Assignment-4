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


#endif //QUESTION3_PLOTDATA_H
