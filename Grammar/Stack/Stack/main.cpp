#include <iostream>
using namespace std;

#define MAX_STACK_SIZE 100

int top;
int stack[MAX_STACK_SIZE];

void stackInit(void) {
    top = 0;
}
int stackIsEmpty(void) {
    return (top == 0);
}
int stackIsFull(void) {
    return(top == MAX_STACK_SIZE);
}
void stackPush(int value) {
    if(stackIsFull()) {
        printf("stack overflow");
    }
    stack[top] = value;
    top++;
}
int stackPop() {
    if(stackIsEmpty()) {
        printf("stack is empty");
        return 0;
    }
    top--;
    return stack[top];
}
