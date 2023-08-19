#ifndef OPERATIONS_H
#define OPERATIONS_H

struct Tree {
    int up;
    unsigned volume;
    char* arr;
};
struct Tree* new_tree(unsigned volume);
char upper(struct Tree* tree);
int empty(struct Tree* tree);
char take(struct Tree* tree);
void put(struct Tree* tree, char ch);
int priority(char ch);
void Polish_Notation(const char* inp, char* res);

#endif