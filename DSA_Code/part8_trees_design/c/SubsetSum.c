#include <stdio.h>

int items[4] = {3, 4, 5, 2};
int chosen[4];                 // 1 = item is in the subset
int target = 9;

void solve(int i, int sum) {
    if (sum == target) {                       // a solution: print it
        printf("Subset:");
        for (int k = 0; k < 4; k++)
            if (chosen[k]) printf(" %d", items[k]);
        printf("\n");
        return;
    }
    if (i == 4 || sum > target) return;        // dead end: BACKTRACK

    chosen[i] = 1;  solve(i + 1, sum + items[i]);   // try including item i
    chosen[i] = 0;  solve(i + 1, sum);              // then try excluding it
}

int main() {
    solve(0, 0);
    return 0;
}
