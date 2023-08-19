#include "input.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input_str(char *str) {
    char ch;
    int lel = 1;
    while ((ch = getchar()) != '\n') {
        str[lel - 1] = ch;
        lel++;
        str = (char *)realloc(str, lel);
    }
    str[lel - 1] = '\0';
}
void leksel(char *input, char *leksels, int i, int *j) {
    brobrc(input, leksels, i, j);
    sumsub(input, leksels, i, j);
    muldiv(input, leksels, i, j);
    sincos(input, leksels, i, j);
    tancot(input, leksels, i, j);
    sqrlog(input, leksels, i, j);
    number(input, leksels, i, j);
    ekseks(input, leksels, i, j);
    leksels = (char *)realloc(leksels, 1);
    leksels[*j] = '\0';
}

void brobrc(const char *input, char *leksels, int i, int *j) {
    int lel = 0;
    if (input[i] == '(') {
        lel += 2;
        leksels = (char *)realloc(leksels, lel);
        leksels[*j] = '(';
        leksels[*j + 1] = ' ';
        *j += 2;
    }
    if (input[i] == ')') {
        lel += 2;
        leksels = (char *)realloc(leksels, lel);
        leksels[*j] = ')';
        leksels[*j + 1] = ' ';
        *j += 2;
    }
}

void sumsub(const char *input, char *leksels, int i, int *j) {
    int lel = 0;
    if (input[i] == '+') {
        lel += 2;
        leksels = (char *)realloc(leksels, lel);
        leksels[*j] = '+';
        leksels[*j + 1] = ' ';
        *j += 2;
    }
    if (input[i] == '-' && i != 0 && input[i - 1] != '(') {
        lel += 2;
        leksels = (char *)realloc(leksels, lel);
        leksels[*j] = '-';
        leksels[*j + 1] = ' ';
        *j += 2;
    }
    if ((input[i] == '-' && i == 0) || (input[i] == '(' && input[i + 1] == '-')) {
        lel += 2;
        leksels = (char *)realloc(leksels, lel);
        leksels[*j] = '~';
        leksels[*j + 1] = ' ';
        *j += 2;
    }
}

void muldiv(const char *input, char *leksels, int i, int *j) {
    int lel = 0;
    if (input[i] == '*') {
        lel += 2;
        leksels = (char *)realloc(leksels, lel);
        leksels[*j] = '*';
        leksels[*j + 1] = ' ';
        *j += 2;
    }
    if (input[i] == '/') {
        lel += 2;
        leksels = (char *)realloc(leksels, lel);
        leksels[*j] = '/';
        leksels[*j + 1] = ' ';
        *j += 2;
    }
}

void sincos(const char *input, char *leksels, int i, int *j) {
    int lel = 0;
    if (input[i] == 's' && input[i + 1] == 'i' && input[i + 2] == 'n') {
        lel += 2;
        leksels = (char *)realloc(leksels, lel);
        leksels[*j] = 's';
        leksels[*j + 1] = ' ';
        *j += 2;
    }
    if (input[i] == 'c' && input[i + 1] == 'o' && input[i + 2] == 's') {
        lel += 2;
        leksels = (char *)realloc(leksels, lel);
        leksels[*j] = 'c';
        leksels[*j + 1] = ' ';
        *j += 2;
    }
}

void tancot(const char *input, char *leksels, int i, int *j) {
    int lel = 0;
    if (input[i] == 't' && input[i + 1] == 'a' && input[i + 2] == 'n') {
        lel += 2;
        leksels = (char *)realloc(leksels, lel);
        leksels[*j] = 't';
        leksels[*j + 1] = ' ';
        *j += 2;
    }
    if (input[i] == 'c' && input[i + 1] == 't' && input[i + 2] == 'g') {
        lel += 2;
        leksels = (char *)realloc(leksels, lel);
        leksels[*j] = 'k';
        leksels[*j + 1] = ' ';
        *j += 2;
    }
}

void sqrlog(const char *input, char *leksels, int i, int *j) {
    int lel = 0;
    if (input[i] == 's' && input[i + 1] == 'q' && input[i + 2] == 'r' && input[i + 3] == 't') {
        lel += 2;
        leksels = (char *)realloc(leksels, lel);
        leksels[*j] = 'q';
        leksels[*j + 1] = ' ';
        *j += 2;
    }
    if (input[i] == 'l' && input[i + 1] == 'n') {
        lel += 2;
        leksels = (char *)realloc(leksels, lel);
        leksels[*j] = 'l';
        leksels[*j + 1] = ' ';
        *j += 2;
    }
}

void number(const char *input, char *leksels, int i, int *j) {
    int lel = 0;
    if (input[i] == '.') {
        lel += 1;
        leksels = (char *)realloc(leksels, lel);
        leksels[*j] = input[i];
        *j += 1;
    }
    if (input[i] >= '0' && input[i] <= '9') {
        if (input[i + 1] >= '0' && input[i + 1] <= '9') {
            lel += 1;
            leksels = (char *)realloc(leksels, lel);
            leksels[*j] = input[i];
            *j += 1;
        } else if (input[i + 1] == '.') {
            lel += 1;
            leksels = (char *)realloc(leksels, lel);
            leksels[*j] = input[i];
            *j += 1;
        } else {
            lel += 2;
            leksels = (char *)realloc(leksels, lel);
            leksels[*j] = input[i];
            leksels[*j + 1] = ' ';
            *j += 2;
        }
    }
}

void ekseks(const char *input, char *leksels, int i, int *j) {
    int lel = 0;
    if (input[i] == 'x') {
        lel += 2;
        leksels = (char *)realloc(leksels, lel);
        leksels[*j] = 'x';
        leksels[*j + 1] = ' ';
        *j += 2;
    }
    if (input[i] == 'X') {
        lel += 2;
        leksels = (char *)realloc(leksels, lel);
        leksels[*j] = 'X';
        leksels[*j + 1] = ' ';
        *j += 2;
    }
}
