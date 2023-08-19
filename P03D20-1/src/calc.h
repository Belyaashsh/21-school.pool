#ifndef CALC_H
#define CALC_H
#define MAX_SIZE 100
typedef struct {
    unsigned volume;
    double data[MAX_SIZE];
    int top;
} Stack;
void init(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void push(Stack *s, double value);
double pop(Stack *s);
double evaluatePostfix(char *expression, double x);

#endif