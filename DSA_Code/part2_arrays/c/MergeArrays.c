#include <stdio.h>

int main() {
    int a[3] = {1, 3, 5};
    int b[4] = {2, 4, 6, 8};
    int c[7];                          // size = 3 + 4

    for (int i = 0; i < 3; i++) c[i] = a[i];
    for (int j = 0; j < 4; j++) c[3 + j] = b[j];

    printf("Merged: ");
    for (int k = 0; k < 7; k++) printf("%d ", c[k]);
    printf("\n");
    return 0;
}
