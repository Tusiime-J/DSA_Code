public class MultiplierList {

    static class ListNode {
        int val;
        ListNode next;
        ListNode(int val) { this.val = val; }
    }

    static ListNode multiplyLinkedList(ListNode head, int k) {
        if (k == 0) return new ListNode(0);

        ListNode dummy = new ListNode(0);     // helper node to build the new list
        ListNode tail = dummy;
        int carry = 0;

        while (head != null || carry > 0) {
            int product = carry;
            if (head != null) {
                product += head.val * k;
                head = head.next;
            }
            tail.next = new ListNode(product % 10);
            tail = tail.next;
            carry = product / 10;
        }
        return dummy.next;
    }

    static void printList(ListNode n) {
        System.out.print("head");
        for (; n != null; n = n.next) System.out.print(" -> [" + n.val + "]");
        System.out.println(" -> null");
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(9);      // the number 99
        head.next = new ListNode(9);

        printList(multiplyLinkedList(head, 5));   // head -> [5] -> [9] -> [4] -> null
    }
}
