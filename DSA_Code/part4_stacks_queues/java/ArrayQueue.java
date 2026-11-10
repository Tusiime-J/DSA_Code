public class ArrayQueue {
    private int[] queue = new int[5];
    private int front = 0, rear = -1, count = 0;

    void enqueue(int x) {
        if (count == queue.length) { System.out.println("Queue full"); return; }
        rear = (rear + 1) % queue.length;      // wrap around
        queue[rear] = x;
        count++;
    }

    int dequeue() {
        if (count == 0) { System.out.println("Queue empty"); return -1; }
        int x = queue[front];
        front = (front + 1) % queue.length;
        count--;
        return x;
    }

    void display() {
        int idx = front;
        for (int i = 0; i < count; i++) {
            System.out.print(queue[idx] + " ");
            idx = (idx + 1) % queue.length;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        ArrayQueue q = new ArrayQueue();
        q.enqueue(10); q.enqueue(20); q.enqueue(30);
        q.display();                                  // 10 20 30
        System.out.println("Dequeued: " + q.dequeue());   // 10
        q.display();                                  // 20 30
    }
}
