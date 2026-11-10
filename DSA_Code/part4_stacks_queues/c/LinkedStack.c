#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *top = NULL;

void push(int x) {
    Node *n = malloc(sizeof(Node));
    n->data = x;
    n->next = top;                   // new node points to the old top
    top = n;
}

int pop() {
    if (top == NULL) { printf("Stack underflow\n"); return -1; }
    Node *temp = top;
    int x = temp->data;
    top = top->next;
    free(temp);
    return x;
}

int peek()    { return (top == NULL) ? -1 : top->data; }
int isEmpty() { return top == NULL; }

int main() {
    push(10); push(20); push(30);
    printf("Top: %d\n", peek());
    printf("Popped: %d\n", pop());
    printf("Popped: %d\n", pop());
    printf("Empty? %s\n", isEmpty() ? "yes" : "no");
    return 0;
}
