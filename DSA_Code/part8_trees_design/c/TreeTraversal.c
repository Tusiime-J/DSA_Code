#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *newNode(int d) {
    Node *n = malloc(sizeof(Node));
    n->data = d;
    n->left = n->right = NULL;
    return n;
}

// ---- Depth-first (recursion) ----
void preorder(Node *r)  { if (!r) return; printf("%d ", r->data); preorder(r->left);  preorder(r->right); }
void inorder(Node *r)   { if (!r) return; inorder(r->left);  printf("%d ", r->data); inorder(r->right); }
void postorder(Node *r) { if (!r) return; postorder(r->left); postorder(r->right); printf("%d ", r->data); }

// ---- Breadth-first (queue) ----
void levelOrder(Node *root) {
    Node *queue[50];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        Node *cur = queue[front++];             // dequeue
        printf("%d ", cur->data);
        if (cur->left)  queue[rear++] = cur->left;    // enqueue children
        if (cur->right) queue[rear++] = cur->right;
    }
}

int main() {
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Preorder : ");  preorder(root);   printf("\n");   // 1 2 4 5 3
    printf("Inorder  : ");  inorder(root);    printf("\n");   // 4 2 5 1 3
    printf("Postorder: ");  postorder(root);  printf("\n");   // 4 5 2 3 1
    printf("Level    : ");  levelOrder(root);  printf("\n");   // 1 2 3 4 5
    return 0;
}
