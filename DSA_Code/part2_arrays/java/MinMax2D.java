public class MinMax2D {
    // returns {value, row, column}
    static int[] findMin(int[][] m) {
        int[] best = {m[0][0], 0, 0};
        for (int i = 0; i < m.length; i++)
            for (int j = 0; j < m[i].length; j++)
                if (m[i][j] < best[0]) best = new int[]{m[i][j], i, j};
        return best;
    }

    static int[] findMax(int[][] m) {
        int[] best = {m[0][0], 0, 0};
        for (int i = 0; i < m.length; i++)
            for (int j = 0; j < m[i].length; j++)
                if (m[i][j] > best[0]) best = new int[]{m[i][j], i, j};
        return best;
    }

    public static void main(String[] args) {
        int[][] m = {{5, 8, 2}, {9, 1, 7}, {4, 6, 3}};
        int[] min = findMin(m);
        int[] max = findMax(m);
        System.out.println("Minimum = " + min[0] + " at row " + min[1] + ", column " + min[2]);
        System.out.println("Maximum = " + max[0] + " at row " + max[1] + ", column " + max[2]);
    }
}
