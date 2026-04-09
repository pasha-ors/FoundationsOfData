#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;     
    int top;        
    int capacity;   
} Stack;

Stack* createStack(int initial_capacity){
    Stack* stack = malloc(sizeof(Stack));
    if(stack == NULL){
        printf("Memory allocation failed!\n"); 
        exit(1);
    }

    stack->data = malloc(initial_capacity * sizeof(int));
    if(stack->data == NULL){
        printf("Memory allocation failed!\n"); 
        exit(1);
    }

    stack->top = -1;
    stack->capacity = initial_capacity;

    return stack;
}

void push(Stack* stack, int value){
    
    if(stack->top + 1 == stack->capacity){
        stack->capacity *= 2;
        int* tmp = realloc(stack->data, stack->capacity * sizeof(int));
        if(tmp == NULL){
            printf("Re-allocation failed!\n");
            exit(1);
        }
        stack->data = tmp;
    }
    stack->top += 1;
    stack->data[stack->top] = value;
}

int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack->data[stack->top];
    stack->top -= 1;
}

int peek(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->data[stack->top];
}

void printStack(Stack *stack) {
    for(int i = stack->top; i > -1; i--){
        printf("[%d]\n", stack->data[i]);
    }
}

void freeStack(Stack *stack) {
    free(stack->data);
    free(stack);
}

int main() {
    Stack *stack = createStack(2);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30); // trigger resize

    printf("Top element: %d\n", peek(stack)); // 30

    printStack(stack);

    freeStack(stack);
    return 0;
}