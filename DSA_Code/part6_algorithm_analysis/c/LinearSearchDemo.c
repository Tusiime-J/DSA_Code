#include <stdio.h>

int linearSearch(int a[], int n, int key, int *comparisons) {
    *comparisons = 0;
    for (int i = 0; i < n; i++) {
        (*comparisons)++;                 // count each comparison
        if (a[i] == key) return i;        // found: return its position
    }
    return -1;                            // not found
}

int main() {
    int a[5] = {7, 3, 9, 1, 5};
    int count;

    linearSearch(a, 5, 7, &count);
    printf("Best case  (key 7): %d comparison(s)\n", count);    // 1
    linearSearch(a, 5, 5, &count);
    printf("Worst case (key 5): %d comparison(s)\n", count);    // 5
    linearSearch(a, 5, 8, &count);
    printf("Not found  (key 8): %d comparison(s)\n", count);    // 5
    return 0;
}
