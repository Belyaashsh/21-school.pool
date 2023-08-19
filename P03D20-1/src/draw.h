#ifndef DRAW_H
#define DRAW_H
#define COLS 80
#define ROWS 25

void init_field(int matrix[][COLS], const int coordinates[COLS]);
void render_field(int matrix[][COLS]);
void init_coordinates(int coordinates[COLS], char* res);
double polish_notation(char* res, double x);

#endif