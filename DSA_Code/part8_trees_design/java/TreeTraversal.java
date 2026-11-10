import java.util.LinkedList;
import java.util.Queue;

public class TreeTraversal {
    static class Node {
        int data;
        Node left, right;
        Node(int data) { this.data = data; }
    }

    // ---- Depth-first (recursion) ----
    static void preorder(Node r)  { if (r == null) return; System.out.print(r.data + " "); preorder(r.left);  preorder(r.right); }
    static void inorder(Node r)   { if (r == null) return; inorder(r.left);  System.out.print(r.data + " "); inorder(r.right); }
    static void postorder(Node r) { if (r == null) return; postorder(r.left); postorder(r.right); System.out.print(r.data + " "); }

    // ---- Breadth-first (queue) ----
    static void levelOrder(Node root) {
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            Node cur = queue.poll();                  // dequeue
            System.out.print(cur.data + " ");
            if (cur.left != null)  queue.add(cur.left);   // enqueue children
            if (cur.right != null) queue.add(cur.right);
        }
    }

    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);

        System.out.print("Preorder : ");  preorder(root);   System.out.println();   // 1 2 4 5 3
        System.out.print("Inorder  : ");  inorder(root);    System.out.println();   // 4 2 5 1 3
        System.out.print("Postorder: ");  postorder(root);  System.out.println();   // 4 5 2 3 1
        System.out.print("Level    : ");  levelOrder(root);  System.out.println();   // 1 2 3 4 5
    }
}
