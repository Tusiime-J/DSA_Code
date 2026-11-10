public class LinkedQueue {
    private class Node {
        int data;
        Node next;
        Node(int data) { this.data = data; }
    }

    private Node front = null, rear = null;

    void enqueue(int x) {
        Node n = new Node(x);
        if (rear == null) front = rear = n;   // queue was empty
        else { rear.next = n; rear = n; }
    }

    int dequeue() {
        if (front == null) { System.out.println("Queue empty"); return -1; }
        int x = front.data;
        front = front.next;
        if (front == null) rear = null;       // queue became empty
        return x;
    }

    void display() {
        for (Node n = front; n != null; n = n.next) System.out.print(n.data + " ");
        System.out.println();
    }

    public static void main(String[] args) {
        LinkedQueue q = new LinkedQueue();
        q.enqueue(10); q.enqueue(20); q.enqueue(30);
        q.display();                                  // 10 20 30
        System.out.println("Dequeued: " + q.dequeue());   // 10
        q.display();                                  // 20 30
    }
}
