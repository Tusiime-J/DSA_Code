#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = 0, rear = -1, count = 0;

void enqueue(int x) {
    if (count == MAX) { printf("Queue full\n"); return; }
    rear = (rear + 1) % MAX;          // wrap around
    queue[rear] = x;
    count++;
}

int dequeue() {
    if (count == 0) { printf("Queue empty\n"); return -1; }
    int x = queue[front];
    front = (front + 1) % MAX;
    count--;
    return x;
}

void display() {
    int idx = front;
    for (int i = 0; i < count; i++) {
        printf("%d ", queue[idx]);
        idx = (idx + 1) % MAX;
    }
    printf("\n");
}

int main() {
    enqueue(10); enqueue(20); enqueue(30);
    display();                                   // 10 20 30
    printf("Dequeued: %d\n", dequeue());         // 10
    display();                                   // 20 30
    return 0;
}
