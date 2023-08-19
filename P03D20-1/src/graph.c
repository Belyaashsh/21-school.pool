#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "draw.h"

#define COLS 80
#define ROWS 25

#include "Operations.h"
#include "input.h"

int main() {
    char *input = NULL;
    input = (char *)malloc(sizeof(char));
    input_str(input);
    char *leksels = NULL;
    leksels = (char *)malloc(sizeof(char));
    int i, j;
    i = j = 0;
    while (input[i] != '\0') {
        leksel(input, leksels, i, &j);
        i++;
    }
    char result[strlen(leksels)];
    Polish_Notation(leksels, result);
    int coordinates[COLS];
    int matrix[ROWS][COLS];
    init_coordinates(coordinates, result);
    init_field(matrix, coordinates);
    render_field(matrix);
    free(input);
    free(leksels);
    return 0;
}
