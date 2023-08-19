#include "calc.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void init(Stack *s) { s->top = -1; }

int isEmpty(Stack *s) { return s->top == -1; }

int isFull(Stack *s) { return s->top == MAX_SIZE - 1; }

void push(Stack *s, double value) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->data[++s->top] = value;
}

double pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->data[s->top--];
}

double evaluatePostfix(char *expression, double x) {
    Stack stack;
    init(&stack);

    int i = 0;
    while (expression[i] != '\0') {
        if ((expression[i] >= '0' && expression[i] <= '9') || expression[i] == 'x' || expression[i] == 'X') {
            (expression[i] >= '0' && expression[i] <= '9') ? push(&stack, expression[i] - '0')
                                                           : push(&stack, x);
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' ||
                   expression[i] == '/') {
            double op2 = pop(&stack);
            double op1 = pop(&stack);
            double result;
            switch (expression[i]) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
            }
            push(&stack, result);
        } else if (expression[i] == 's' || expression[i] == 'c' || expression[i] == 't' ||
                   expression[i] == 'k' || expression[i] == 'l' || expression[i] == 'q' ||
                   expression[i] == '~') {
            double operand = pop(&stack);
            double result;
            switch (expression[i]) {
                case 's':
                    result = sin(operand);
                    break;
                case 'c':
                    result = cos(operand);
                    break;
                case 't':
                    result = tan(operand);
                    break;
                case 'k':
                    result = 1 / tan(operand);
                    break;
                case 'l':
                    result = log(operand);
                    break;
                case 'q':
                    result = sqrt(operand);
                    break;
                case '~':
                    result = operand * (-1);
            }
            push(&stack, result);
        }
        i++;
    }

    return pop(&stack);
}

// int main() {
//   char expression[] = "5l";
//   double result = evaluatePostfix(expression);
//   printf("Result: %f\n", result);

//   return 0;
// }
