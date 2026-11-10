public class LinearSearchDemo {
    static int comparisons;

    static int linearSearch(int[] a, int key) {
        comparisons = 0;
        for (int i = 0; i < a.length; i++) {
            comparisons++;                // count each comparison
            if (a[i] == key) return i;    // found: return its position
        }
        return -1;                        // not found
    }

    public static void main(String[] args) {
        int[] a = {7, 3, 9, 1, 5};

        linearSearch(a, 7);
        System.out.println("Best case  (key 7): " + comparisons + " comparison(s)");   // 1
        linearSearch(a, 5);
        System.out.println("Worst case (key 5): " + comparisons + " comparison(s)");   // 5
        linearSearch(a, 8);
        System.out.println("Not found  (key 8): " + comparisons + " comparison(s)");   // 5
    }
}
