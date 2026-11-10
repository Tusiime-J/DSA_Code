#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

ListNode *newNode(int v) {
    ListNode *n = malloc(sizeof(ListNode));
    n->val = v;
    n->next = NULL;
    return n;
}

ListNode *multiplyLinkedList(ListNode *head, int k) {
    if (k == 0) return newNode(0);

    ListNode dummy = {0, NULL};          // helper node to build the new list
    ListNode *tail = &dummy;
    int carry = 0;

    while (head != NULL || carry > 0) {
        int product = carry;
        if (head != NULL) {
            product += head->val * k;
            head = head->next;
        }
        tail->next = newNode(product % 10);
        tail = tail->next;
        carry = product / 10;
    }
    return dummy.next;
}

void printList(ListNode *n) {
    printf("head");
    for (; n != NULL; n = n->next) printf(" -> [%d]", n->val);
    printf(" -> null\n");
}

int main() {
    ListNode *head = newNode(9);          // the number 99
    head->next = newNode(9);

    ListNode *result = multiplyLinkedList(head, 5);
    printList(result);                    // head -> [5] -> [9] -> [4] -> null
    return 0;
}
