import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Supermarket {
    static final int COUNTERS = 3;
    static List<Queue<String>> queues = new ArrayList<>();

    static void customerArrival(String name) {
        int shortest = 0;
        for (int i = 1; i < COUNTERS; i++)
            if (queues.get(i).size() < queues.get(shortest).size()) shortest = i;

        queues.get(shortest).add(name);                   // join at the rear
        System.out.println(name + " joins counter " + (shortest + 1));
    }

    static void processNextCustomer(int counter) {
        Queue<String> q = queues.get(counter - 1);
        if (q.isEmpty()) { System.out.println("Counter " + counter + " is empty"); return; }
        System.out.println("Counter " + counter + " serves " + q.poll());   // front customer
    }

    static void displayQueue(int counter) {
        Queue<String> q = queues.get(counter - 1);
        System.out.print("Counter " + counter + ": ");
        if (q.isEmpty()) System.out.print("(empty)");
        for (String name : q) System.out.print("[" + name + "] ");
        System.out.println();
    }

    public static void main(String[] args) {
        for (int i = 0; i < COUNTERS; i++) queues.add(new LinkedList<>());

        customerArrival("Amina");
        customerArrival("Brian");
        customerArrival("Carol");
        customerArrival("David");
        customerArrival("Esther");
        for (int i = 1; i <= COUNTERS; i++) displayQueue(i);

        processNextCustomer(1);
        displayQueue(1);
    }
}
