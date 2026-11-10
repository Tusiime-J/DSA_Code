#include <stdio.h>

int main() {
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};   // m x n = 2 x 3
    int B[1][3] = {{7, 8, 9}};              // p x q = 1 x 3  (q must equal n)
    int C[3][3];                            // (m + p) x n

    for (int i = 0; i < 2; i++)             // copy A
        for (int j = 0; j < 3; j++) C[i][j] = A[i][j];
    for (int i = 0; i < 1; i++)             // copy B below A
        for (int j = 0; j < 3; j++) C[2 + i][j] = B[i][j];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) printf("%d ", C[i][j]);
        printf("\n");
    }
    return 0;
}
