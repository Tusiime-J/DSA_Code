public class ArrayStack {
    private int[] data = new int[5];
    private int top = -1;                 // -1 means empty

    void push(int x) {
        if (top == data.length - 1) { System.out.println("Stack overflow"); return; }
        data[++top] = x;
    }

    int pop() {
        if (isEmpty()) { System.out.println("Stack underflow"); return -1; }
        return data[top--];
    }

    int peek()        { return isEmpty() ? -1 : data[top]; }
    boolean isEmpty() { return top == -1; }

    public static void main(String[] args) {
        ArrayStack s = new ArrayStack();
        s.push(10); s.push(20); s.push(30);
        System.out.println("Top: " + s.peek());
        System.out.println("Popped: " + s.pop());
        System.out.println("Popped: " + s.pop());
        System.out.println("Empty? " + (s.isEmpty() ? "yes" : "no"));
    }
}
