#include <stdio.h>

int main() {
    int a[3] = {10, 20, 30};
    int b[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int c[2][2][2] = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};

    printf("1D base address = %p\n", (void *)a);
    for (int i = 0; i < 3; i++)
        printf("a[%d] = %d  at %p\n", i, a[i], (void *)&a[i]);

    printf("\n2D base address = %p\n", (void *)b);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            printf("b[%d][%d] = %d  at %p\n", i, j, b[i][j], (void *)&b[i][j]);

    printf("\n3D base address = %p\n", (void *)c);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                printf("c[%d][%d][%d] = %d  at %p\n", i, j, k, c[i][j][k], (void *)&c[i][j][k]);
    return 0;
}
