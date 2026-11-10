public class MergeArrays {
    public static void main(String[] args) {
        int[] a = {1, 3, 5};
        int[] b = {2, 4, 6, 8};
        int[] c = new int[a.length + b.length];

        for (int i = 0; i < a.length; i++) c[i] = a[i];
        for (int j = 0; j < b.length; j++) c[a.length + j] = b[j];

        System.out.println("Merged: " + java.util.Arrays.toString(c));
    }
}
