//
// Created by jolsz on 13.03.2024.
//

#ifndef QUESTION3_DATAANALYSIS_H
#define QUESTION3_DATAANALYSIS_H

#include "stdlib.h"
#include "stdio.h"
#define MAX_POINTS 10

double calculate_slope(int n, double x[], double y[]);
double calculate_intercept(int n, double x[], double y[], double slope) ;
double** calculate_points_on_line(int num_points, double x_min, double x_max, double slope, double intercept);
#endif //QUESTION3_DATAANALYSIS_H
