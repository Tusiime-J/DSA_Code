public class KnapsackBB {
    static int[] value  = {10, 7, 5};
    static int[] weight = {4, 3, 2};
    static int capacity = 5;
    static int best = 0;                        // best value found so far

    static void solve(int i, int w, int v, int remaining) {
        if (w > capacity) return;               // too heavy: invalid
        if (v > best) best = v;                 // update the best answer
        if (i == value.length) return;
        if (v + remaining <= best) return;      // BOUND: cannot beat best, prune

        solve(i + 1, w + weight[i], v + value[i], remaining - value[i]);   // branch: take item i
        solve(i + 1, w, v, remaining - value[i]);                          // branch: skip item i
    }

    public static void main(String[] args) {
        solve(0, 0, 0, 22);                     // 22 = 10 + 7 + 5
        System.out.println("Best value = " + best);   // 12 (items 2 and 3)
    }
}
