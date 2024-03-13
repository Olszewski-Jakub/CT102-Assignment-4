//
// Created by jolsz on 13.03.2024.
//

#include "../include/PlotData.h"

wchar_t *ConvertToWString(const char *str) {
    size_t size = strlen(str) + 1;
    wchar_t *wstr = malloc(size * sizeof(wchar_t));
    if (wstr) {
        mbstowcs(wstr, str, size);
    }
    return wstr;
}


void drawAvgTimeVsAlg(double *avgTime, int size, char *title, char *yLabel, char *xLabel[], char *GRAPH_PATH) {


    //Drawbar plot from settings
    RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();
    StringReference *errorMessage;
    errorMessage = (StringReference *) malloc(sizeof(StringReference));

    BarPlotSettings *settings = (BarPlotSettings *) malloc(sizeof(BarPlotSettings));

    RGBA *color = CreateRGBColor(1, 0, 0); // Red color
    BarPlotSeries *series = createBarPlotSeries(avgTime, size, color);

    wchar_t *titleW = ConvertToWString(title);
    wchar_t *yLabelW = ConvertToWString(yLabel);

    double width = size * 200;
    double height = width / 2;

    settings->barPlotSeries = &series;
    settings->barPlotSeriesLength = 1;
    settings->width = width;
    settings->height = height;
    settings->autoBoundaries = true;
    settings->yMax = 100.0;
    settings->yMin = 0.0;
    settings->autoPadding = true;
    settings->xPadding = 10.0;
    settings->yPadding = 10.0;
    settings->title = titleW;
    settings->titleLength = wcslen(settings->title); // automatically calculated
    settings->showGrid = true;
    settings->gridColor = CreateRGBColor(0.5, 0.5, 0.5);

    settings->yLabel = yLabelW;
    settings->yLabelLength = wcslen(settings->yLabel); // automatically calculated
    settings->autoColor = true;
    settings->grayscaleAutoColor = false;
    settings->autoSpacing = true;
    settings->groupSeparation = 10.0;
    settings->barSeparation = 20.0;
    settings->autoLabels = false;
    settings->xLabels = (StringReference **) malloc(sizeof(StringReference *) * size);

    for (int i = 0; i < size; i++) {
        settings->xLabels[i] = (StringReference *) malloc(sizeof(StringReference));
        settings->xLabels[i]->string = ConvertToWString(xLabel[i]);
        settings->xLabels[i]->stringLength = strlen(xLabel[i]);
    }
    settings->xLabelsLength = size;
    settings->barBorder = true;

    // Create the bar plot
    DrawBarPlotFromSettings(imageReference, settings, errorMessage);

    // Save the image to a file
    size_t length;
    double *pngdata = ConvertToPNG(&length, imageReference->image);

    WriteToFile(pngdata, length, combineCharArrays(GRAPH_PATH, "//avg_time_vs_alg.png"));
    DeleteImage(imageReference->image);
    free(imageReference);
    free(settings);
    free(errorMessage);
    free(pngdata);
    free(series);
    free(color);
    free(titleW);
    free(yLabelW);

}


BarPlotSeries *createBarPlotSeries(double *avgTime, size_t length, RGBA *color) {
    // Allocate memory for a new BarPlotSeries
    BarPlotSeries *series = (BarPlotSeries *) malloc(sizeof(BarPlotSeries));

    // Set the ys to the avgTime array
    series->ys = avgTime;

    // Set the ysLength to the length of the avgTime array
    series->ysLength = length;

    // Set the color
    series->color = color;

    return series;
}

// Draw scatter plot for each sorting algorithm comparisons vs input size on one graph
void drawCompVsTimeTaken(double comparisons[], double timeTaken[], int size, const char *graphPath) {
    ScatterPlotSeries **series = (ScatterPlotSeries **) malloc(sizeof(ScatterPlotSeries *) * 2);
    // Using Linear Regression to find the best fit line

    //Find amx and min of comparisons
    double max = comparisons[0];
    double min = comparisons[0];
    for (int i = 0; i < size; i++) {
        if (comparisons[i] > max) {
            max = comparisons[i];
        }
        if (comparisons[i] < min) {
            min = comparisons[i];
        }
    }

    //Find amx and min of timeTaken
    double maxTime = timeTaken[0];
    double minTime = timeTaken[0];
    for (int i = 0; i < size; i++) {
        if (timeTaken[i] > maxTime) {
            maxTime = timeTaken[i];
        }
        if (timeTaken[i] < minTime) {
            minTime = timeTaken[i];
        }
    }

    double slope = calculate_slope(size, comparisons, timeTaken);
    double intercept = calculate_intercept(size, comparisons, timeTaken, slope);
    double **points = calculate_points_on_line(2, 0, max, slope, intercept);



    double *xFit = (double *) malloc(sizeof(double) * 2);
    double *yFit = (double *) malloc(sizeof(double) * 2);
    //trasdfer points from 2d array to 1d array
    for (int i = 0; i < 2; i++) {
        xFit[i] = points[i][0];
        yFit[i] = points[i][1];
    }

    ScatterPlotSeries *bestFitSeries = createScatterPlotSeries(xFit, yFit, 2, CreateRGBColor(0.0, 0.482, 1),
                                                               1, 0);
    ScatterPlotSeries *pointsSeries = createScatterPlotSeries(comparisons, timeTaken, size, CreateRGBColor(1, 0, 0), 0,
                                                              0);
    series[0] = bestFitSeries;
    series[1] = pointsSeries;

    char *xLabel = "Comparisons (Millions)";
    char *yLabel = "Time taken (ms)";
    char *title = "Comparisons vs Time Taken";
    RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();
    StringReference *errorMessage;
    errorMessage = (StringReference *) malloc(sizeof(StringReference));

    ScatterPlotSettings *settings = (ScatterPlotSettings *) malloc(sizeof(ScatterPlotSettings));

    settings->scatterPlotSeries = series;
    settings->scatterPlotSeriesLength = 2;
    settings->autoBoundaries = true;
    settings->xMax = 100.0;
    settings->xMin = -10.0;
    settings->yMax = 1.0;
    settings->yMin = -0.1;
    settings->autoPadding = true;
    settings->xPadding = 10.0;
    settings->yPadding = 10.0;
    settings->xLabel = ConvertToWString(xLabel);
    settings->xLabelLength = strlen(xLabel);
    settings->yLabel = ConvertToWString(yLabel);
    settings->yLabelLength = strlen(yLabel);
    settings->title = ConvertToWString(title);
    settings->titleLength = strlen(title);
    settings->showGrid = true;
    settings->gridColor = CreateRGBColor(0.5, 0.5, 0.5);
    settings->xAxisAuto = true;
    settings->xAxisTop = true;
    settings->xAxisBottom = true;
    settings->yAxisAuto = true;
    settings->yAxisLeft = true;
    settings->yAxisRight = false;
    settings->width = 800;
    settings->height = 400;

    DrawScatterPlotFromSettings(imageReference, settings, errorMessage);

    // Save the image to a file
    size_t length;
    double *pngdata = ConvertToPNG(&length, imageReference->image);

    WriteToFile(pngdata, length, combineCharArrays(graphPath, "//comp_vs_time.png"));

    free(settings);
    free(series);
    free(errorMessage);

}

ScatterPlotSeries *
createScatterPlotSeries(double *x, double *y, int size, RGBA *color, int interpolationType, int lineType) {

    ScatterPlotSeries *series = (ScatterPlotSeries *) malloc(sizeof(ScatterPlotSeries));
    series->linearInterpolation = interpolationType;
    series->pointType = L"dots";
    series->pointTypeLength = 4;
    series->lineType = ConvertToWString(lineType == 0 ? "dashed" : "solid");
    series->lineTypeLength = lineType == 0 ? 6 : 5;
    series->lineThickness = 2;
    series->xs = x;
    series->xsLength = size;
    series->ys = y;
    series->ysLength = size;
    series->color = color;

    return series;
}