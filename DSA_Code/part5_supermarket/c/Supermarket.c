#include <stdio.h>
#include <string.h>

#define COUNTERS 3
#define MAXQ 10

char queues[COUNTERS][MAXQ][20];     // customer names, one queue per counter
int  size[COUNTERS] = {0, 0, 0};     // how many customers wait at each counter

void CustomerArrival(char *name) {
    int shortest = 0;
    for (int i = 1; i < COUNTERS; i++)
        if (size[i] < size[shortest]) shortest = i;   // '<' keeps the first on a tie

    if (size[shortest] == MAXQ) { printf("All queues are full\n"); return; }
    strcpy(queues[shortest][size[shortest]], name);   // join at the rear
    size[shortest]++;
    printf("%s joins counter %d\n", name, shortest + 1);
}

void ProcessNextCustomer(int counter) {
    int c = counter - 1;
    if (size[c] == 0) { printf("Counter %d is empty\n", counter); return; }
    printf("Counter %d serves %s\n", counter, queues[c][0]);   // front customer
    for (int i = 1; i < size[c]; i++)                        // everyone moves forward
        strcpy(queues[c][i - 1], queues[c][i]);
    size[c]--;
}

void DisplayQueue(int counter) {
    int c = counter - 1;
    printf("Counter %d: ", counter);
    if (size[c] == 0) printf("(empty)");
    for (int i = 0; i < size[c]; i++) printf("[%s] ", queues[c][i]);
    printf("\n");
}

int main() {
    CustomerArrival("Amina");
    CustomerArrival("Brian");
    CustomerArrival("Carol");
    CustomerArrival("David");
    CustomerArrival("Esther");
    for (int i = 1; i <= COUNTERS; i++) DisplayQueue(i);

    ProcessNextCustomer(1);
    DisplayQueue(1);
    return 0;
}
