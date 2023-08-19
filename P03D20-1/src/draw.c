#define COLS 80
#define ROWS 25
#include "draw.h"

#include <math.h>
#include <stdio.h>

#include "calc.h"

void init_coordinates(int coordinates[COLS], char *res) {
    double step_x = (M_PI * 4.0) / 80.0;
    double step_y = 2.0 / 24.0;
    int index = 0;
    for (double x = 0; x <= (M_PI * 4); x += step_x) {
        double y = polish_notation(res, x);
        double value = -1;
        double y_coord = 0;
        while (value <= y && value <= 1) {
            y_coord++;
            value += step_y;
        }
        coordinates[index] = 0 + y_coord;
        index++;
    }
}

double polish_notation(char *res, double x) { return evaluatePostfix(res, x); }

void init_field(int matrix[][COLS], const int coordinates[COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == coordinates[j]) {
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }
}

void render_field(int matrix[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            ;
            if (matrix[i][j] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        if (i != ROWS - 1) {
            printf("\n");
        }
    }
}
