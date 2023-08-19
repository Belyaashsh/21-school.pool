#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Operations.h"

struct Tree *new_tree(unsigned volume) {
    struct Tree *tree = (struct Tree *)malloc(sizeof(struct Tree));
    tree->volume = volume;
    tree->up = -1;
    tree->arr = (char *)malloc(tree->volume * sizeof(char));
    return tree;
}
//Возвращение верхнего элемента стека
char upper(struct Tree *tree) { return tree->arr[tree->up]; }
//Проверка, пустой ли стек
int empty(struct Tree *tree) {
    if (tree->up == -1) return 1;
    return 0;
}

char take(struct Tree *tree) {
    if (!empty(tree)) {
        return tree->arr[tree->up--];
    }
    return '\0';
}

void put(struct Tree *tree, char ch) { tree->arr[++tree->up] = ch; }
//приоритет операций
int priority(char ch) {
    int ret = 0;
    if (ch == '+' || ch == '-') ret = 1;
    if (ch == '*' || ch == '/') ret = 2;
    if (ch == 's' || ch == 'c' || ch == 't' || ch == 'k' || ch == 'l') ret = 3;
    if (ch == 'q') ret = 4;
    if (ch == '~') ret = 6;
    return ret;
}

void Polish_Notation(const char *inp, char *res) {
    struct Tree *tree = new_tree(strlen(res));
    int i, j;
    i = j = 0;

    while (inp[i] != '\0') {
        if (inp[i] >= '0' && inp[i] <= '9') {
            if (inp[i + 1] >= '0' && inp[i + 1] <= '9') {
                res[j] = inp[i];
                j += 1;
                i += 1;
            } else if (inp[i + 1] == '.') {
                res[j] = inp[i];
                j += 1;
                i += 1;
            } else {
                res[j] = inp[i];
                j += 1;
                i += 1;
                res[j] = ' ';
                j += 1;
            }
        } else if (inp[i] == '.') {
            res[j] = inp[i];
            j += 1;
            i += 1;
        } else if (inp[i] == '(') {
            put(tree, inp[i]);
            i += 1;
        } else if (inp[i] == ')') {
            while (!empty(tree) && upper(tree) != '(') {
                res[j] = take(tree);
                j += 1;
                res[j] = ' ';
                j += 1;
            }
            take(tree);
            i++;
        } else if (inp[i] == 'x' || inp[i] == 'X') {
            res[j] = inp[i];
            j += 1;
            i += 1;
            res[j] = ' ';
            j += 1;
        } else {
            while (!empty(tree) && (priority(upper(tree)) >= priority(inp[i]))) {
                res[j] = take(tree);
                j += 1;
                res[j] = ' ';
                j += 1;
                i += 1;
            }
            put(tree, inp[i]);
            i += 1;
        }
        i += 1;
    }

    while (!empty(tree)) {
        res[j++] = take(tree);
        res[j++] = ' ';
    }
    res[j] = '\0';
    free(tree->arr);
    free(tree);
}
