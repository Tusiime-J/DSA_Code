public class SubsetSum {
    static int[] items = {3, 4, 5, 2};
    static boolean[] chosen = new boolean[4];
    static int target = 9;

    static void solve(int i, int sum) {
        if (sum == target) {                       // a solution: print it
            System.out.print("Subset:");
            for (int k = 0; k < items.length; k++)
                if (chosen[k]) System.out.print(" " + items[k]);
            System.out.println();
            return;
        }
        if (i == items.length || sum > target) return;   // dead end: BACKTRACK

        chosen[i] = true;  solve(i + 1, sum + items[i]);  // try including item i
        chosen[i] = false; solve(i + 1, sum);             // then try excluding it
    }

    public static void main(String[] args) {
        solve(0, 0);
    }
}
