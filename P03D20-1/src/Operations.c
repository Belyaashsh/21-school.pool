#include "Operations.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    if (ch == '~') ret = 5;
    return ret;
}

void Polish_Notation(const char *inp, char *res) {
    struct Tree *tree = new_tree(strlen(inp));
    int i, j;
    i = j = 0;

    while (inp[i] != '\0') {
        while (inp[i] != ' ') {
            if (inp[i] >= '0' && inp[i] <= '9') {
                if (inp[i + 1] >= '0' && inp[i + 1] <= '9') {
                    res[j++] = inp[i++];
                } else if (inp[i + 1] == '.') {
                    res[j++] = inp[i++];
                    res[j++] = inp[i++];
                } else {
                    res[j++] = inp[i++];
                    res[j++] = ' ';
                }
            } else if (inp[i] == '(') {
                put(tree, inp[i++]);
            } else if (inp[i] == ')') {
                while (!empty(tree) && upper(tree) != '(') {
                    res[j++] = take(tree);
                    res[j++] = ' ';
                }
                take(tree);
                i++;
            } else if (inp[i] == 'x' || inp[i] == 'X') {
                res[j++] = inp[i++];
                res[j++] = ' ';
            } else {
                while (!empty(tree) && (priority(upper(tree)) >= priority(inp[i]))) {
                    res[j++] = take(tree);
                    res[j++] = ' ';
                }
                put(tree, inp[i++]);
            }
        }
        i++;
    }
    while (!empty(tree)) {
        res[j++] = take(tree);
        res[j++] = ' ';
    }
    res[j] = '\0';
    free(tree->arr);
    free(tree);
}
