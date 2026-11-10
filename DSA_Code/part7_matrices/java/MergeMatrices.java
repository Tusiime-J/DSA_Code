public class MergeMatrices {
    public static void main(String[] args) {
        int[][] A = {{1, 2, 3}, {4, 5, 6}};   // m x n = 2 x 3
        int[][] B = {{7, 8, 9}};              // p x q = 1 x 3  (q must equal n)
        int[][] C = new int[A.length + B.length][A[0].length];

        for (int i = 0; i < A.length; i++)    // copy A
            for (int j = 0; j < A[0].length; j++) C[i][j] = A[i][j];
        for (int i = 0; i < B.length; i++)    // copy B below A
            for (int j = 0; j < B[0].length; j++) C[A.length + i][j] = B[i][j];

        for (int[] row : C) {
            for (int x : row) System.out.print(x + " ");
            System.out.println();
        }
    }
}
