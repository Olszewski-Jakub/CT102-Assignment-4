//
// Created by jolsz on 13.03.2024.
//

#include "../include/DataAnalysis.h"

double calculate_slope(int n, double x[], double y[]) {
    // Calculate mean of x and y
    double mean_x = 0.0, mean_y = 0.0;
    for (int i = 0; i < n; i++) {
        mean_x += x[i];
        mean_y += y[i];
    }
    mean_x /= n;
    mean_y /= n;

    // Calculate numerator and denominator for slope
    double numerator = 0.0, denominator = 0.0;
    for (int i = 0; i < n; i++) {
        numerator += (x[i] - mean_x) * (y[i] - mean_y);
        denominator += (x[i] - mean_x) * (x[i] - mean_x);
    }

    // Return slope (m)
    return (numerator / denominator);
}

double calculate_intercept(int n, double x[], double y[], double slope) {
    // Calculate mean of x and y (already done in calculate_slope)
    double mean_x = 0.0, mean_y = 0.0;
    for (int i = 0; i < n; i++) {
        mean_x += x[i];
        mean_y += y[i];
    }
    mean_x /= n;
    mean_y /= n;

    // Return intercept (b)
    return (mean_y - slope * mean_x);
}

double** calculate_points_on_line(int num_points, double x_min, double x_max, double slope, double intercept) {
    // Validate input
    if (num_points <= 0 || num_points > MAX_POINTS) {
        printf("Error: Number of points must be positive and less than or equal to %d.\n", MAX_POINTS);
        return NULL;
    }


    // Allocate memory for the points array (dynamic allocation)
    double** points = (double**)malloc(num_points * sizeof(double*));


    for (int i = 0; i < num_points; i++) {
        points[i] = (double*)malloc(2 * sizeof(double));
    }

    // Generate points on the line equation (y = mx + b) using a while loop
    int i = 0;
    double x_value = x_min;
    while (i < num_points) {
        points[i][0] = x_value;
        points[i][1] = slope * x_value + intercept;
        x_value += (x_max - x_min) / (num_points - 1); // Increment with spacing
        i++;
    }

    // Return the points array
    return points;
}