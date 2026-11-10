#include <stdio.h>
#define ROWS 3
#define COLS 3

int findMin(int m[ROWS][COLS], int *row, int *col) {
    int min = m[0][0];
    *row = 0; *col = 0;
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            if (m[i][j] < min) { min = m[i][j]; *row = i; *col = j; }
    return min;
}

int findMax(int m[ROWS][COLS], int *row, int *col) {
    int max = m[0][0];
    *row = 0; *col = 0;
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            if (m[i][j] > max) { max = m[i][j]; *row = i; *col = j; }
    return max;
}

int main() {
    int m[ROWS][COLS] = {{5, 8, 2}, {9, 1, 7}, {4, 6, 3}};
    int r, c;

    int min = findMin(m, &r, &c);
    printf("Minimum = %d at row %d, column %d\n", min, r, c);

    int max = findMax(m, &r, &c);
    printf("Maximum = %d at row %d, column %d\n", max, r, c);
    return 0;
}
