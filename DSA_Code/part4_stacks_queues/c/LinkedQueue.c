#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    Node *n = malloc(sizeof(Node));
    n->data = x;
    n->next = NULL;
    if (rear == NULL) front = rear = n;   // queue was empty
    else { rear->next = n; rear = n; }
}

int dequeue() {
    if (front == NULL) { printf("Queue empty\n"); return -1; }
    Node *temp = front;
    int x = temp->data;
    front = front->next;
    if (front == NULL) rear = NULL;       // queue became empty
    free(temp);
    return x;
}

void display() {
    for (Node *n = front; n != NULL; n = n->next) printf("%d ", n->data);
    printf("\n");
}

int main() {
    enqueue(10); enqueue(20); enqueue(30);
    display();                                   // 10 20 30
    printf("Dequeued: %d\n", dequeue());         // 10
    display();                                   // 20 30
    return 0;
}
