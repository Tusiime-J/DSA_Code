public class LinkedStack {
    private class Node {
        int data;
        Node next;
        Node(int data) { this.data = data; }
    }

    private Node top = null;

    void push(int x) {
        Node n = new Node(x);
        n.next = top;                 // new node points to the old top
        top = n;
    }

    int pop() {
        if (top == null) { System.out.println("Stack underflow"); return -1; }
        int x = top.data;
        top = top.next;
        return x;
    }

    int peek()        { return (top == null) ? -1 : top.data; }
    boolean isEmpty() { return top == null; }

    public static void main(String[] args) {
        LinkedStack s = new LinkedStack();
        s.push(10); s.push(20); s.push(30);
        System.out.println("Top: " + s.peek());
        System.out.println("Popped: " + s.pop());
        System.out.println("Popped: " + s.pop());
        System.out.println("Empty? " + (s.isEmpty() ? "yes" : "no"));
    }
}
