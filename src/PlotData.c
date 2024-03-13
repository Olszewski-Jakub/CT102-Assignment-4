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