import java.util.ArrayList;

public class ArrayListDemo {
    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<>();
        list.add(10);
        list.add(20);
        list.add(30);
        for (int x : list) System.out.print(x + " ");
        System.out.println("\nsize = " + list.size());
    }
}
