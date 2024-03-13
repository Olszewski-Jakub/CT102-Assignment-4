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

    RGBA* color = CreateRGBColor(1, 0, 0); // Red color
    BarPlotSeries* series = createBarPlotSeries(avgTime, size, color);

    wchar_t *titleW = ConvertToWString(title);
    wchar_t *yLabelW = ConvertToWString(yLabel);

    double width = size * 200;
    double height = width / 2;

    settings->barPlotSeries = &series;
    settings->barPlotSeriesLength = 1;
    settings->width = width;
    settings->height =height;
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


BarPlotSeries* createBarPlotSeries(double* avgTime, size_t length, RGBA* color) {
    // Allocate memory for a new BarPlotSeries
    BarPlotSeries* series = (BarPlotSeries*) malloc(sizeof(BarPlotSeries));

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

    char *xLabel = "Comparisons (Millions)";
    char *yLabel = "Time taken (ms)";
    char *title = "Comparisons vs Time Taken";
    RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();
    StringReference *errorMessage;
    errorMessage = (StringReference *) malloc(sizeof(StringReference));

    ScatterPlotSettings *settings = (ScatterPlotSettings *) malloc(sizeof(ScatterPlotSettings));
    ScatterPlotSeries *series = createScatterPlotSeries(comparisons, timeTaken, size,
                                                        CreateRGBColor(1, 0, 0));
    settings->scatterPlotSeries = &series;
    settings->scatterPlotSeriesLength = 1;
    settings->autoBoundaries = true;
    settings->xMax = 100.0;
    settings->xMin = -10.0;
    settings->yMax = 10.0;
    settings->yMin = -1.0;
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
    settings->xAxisTop = false;
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

ScatterPlotSeries *createScatterPlotSeries(double *x, double *y, int size, RGBA *color) {
    ScatterPlotSeries *series = (ScatterPlotSeries *) malloc(sizeof(ScatterPlotSeries));
    series->linearInterpolation = false;
    series->pointType = L"dots";
    series->pointTypeLength = 4;
    series->lineType = L"solid";
    series->lineTypeLength = 5;
    series->lineThickness = 2;
    series->xs = x;
    series->xsLength = size;
    series->ys = y;
    series->ysLength = size;
    series->color = color;

    return series;
}