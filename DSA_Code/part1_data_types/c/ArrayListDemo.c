#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *items;
    int size;
    int capacity;
} ArrayList;

void init(ArrayList *list) {
    list->size = 0;
    list->capacity = 2;
    list->items = malloc(list->capacity * sizeof(int));
}

void add(ArrayList *list, int value) {
    if (list->size == list->capacity) {          // full? double the space
        list->capacity *= 2;
        list->items = realloc(list->items, list->capacity * sizeof(int));
    }
    list->items[list->size++] = value;
}

int get(ArrayList *list, int index) { return list->items[index]; }

int main() {                                    // Q1(d) demo
    ArrayList list;
    init(&list);
    add(&list, 10);
    add(&list, 20);
    add(&list, 30);                              // triggers a resize
    for (int i = 0; i < list.size; i++)
        printf("%d ", get(&list, i));
    printf("\nsize = %d\n", list.size);
    free(list.items);
    return 0;
}
