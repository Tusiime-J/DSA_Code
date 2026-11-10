public class ArrayTraversal {
    public static void main(String[] args) {
        int[] a = {10, 20, 30};
        int[][] b = {{1, 2, 3}, {4, 5, 6}};
        int[][][] c = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};
        int base = 1000, w = 4;                    // pretend base address, bytes per int

        System.out.println("1D array:");
        for (int i = 0; i < a.length; i++)
            System.out.println("a[" + i + "] = " + a[i] + "  address = " + (base + w * i));

        System.out.println("2D array:");
        for (int i = 0; i < b.length; i++)
            for (int j = 0; j < b[i].length; j++)
                System.out.println("b[" + i + "][" + j + "] = " + b[i][j]
                        + "  address = " + (base + w * (i * 3 + j)));

        System.out.println("3D array:");
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    System.out.println("c[" + i + "][" + j + "][" + k + "] = " + c[i][j][k]
                            + "  address = " + (base + w * ((i * 2 + j) * 2 + k)));
    }
}
