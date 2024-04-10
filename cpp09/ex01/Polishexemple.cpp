#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// Structure to represent a stack
struct Stack {
    int top;
    int array[MAX_SIZE];
};

// Function to create a new stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack))
        return -1; // Stack underflow
    return stack->array[stack->top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* exp) {
    struct Stack* stack = createStack();
    int i;
    for (i = 0; exp[i]; ++i) {
        if (isdigit(exp[i])) {
            push(stack, exp[i] - '0');
        } else {
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (exp[i]) {
                case '+': push(stack, val2 + val1); break;
                case '-': push(stack, val2 - val1); break;
                case '*': push(stack, val2 * val1); break;
                case '/': push(stack, val2 / val1); break;
            }
        }
    }
    return pop(stack);
}

int main() {
    char exp[] = "34+5*";
    printf("Result of expression %s is %d\n", exp, evaluatePostfix(exp));
    return 0;
}
