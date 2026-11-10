#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;                       // -1 means empty

void push(int x) {
    if (top == MAX - 1) { printf("Stack overflow\n"); return; }
    stack[++top] = x;
}

int pop() {
    if (top == -1) { printf("Stack underflow\n"); return -1; }
    return stack[top--];
}

int peek()    { return (top == -1) ? -1 : stack[top]; }
int isEmpty() { return top == -1; }

int main() {
    push(10); push(20); push(30);
    printf("Top: %d\n", peek());
    printf("Popped: %d\n", pop());
    printf("Popped: %d\n", pop());
    printf("Empty? %s\n", isEmpty() ? "yes" : "no");
    return 0;
}
