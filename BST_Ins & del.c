#include <stdio.h>
#include <stdlib.h>

typedef struct MyNode {
    int data;
    struct MyNode *left, *right;
} *Node;

Node createNode(int value) {
    Node nn = (Node)malloc(sizeof(struct MyNode));
    if (nn == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    nn->data = value;
    nn->left = nn->right = NULL;
    return nn;
}
Node insert(Node root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}
Node findLargestNode(Node root) {
    while (root->right != NULL)
        root = root->right;
    return root;
}
Node deleteNode(Node root, int key) {
    if (root == NULL) {
        printf("Item not found in tree\n");
        return root;
    }

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        /* Case 1: Leaf node */
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        /* Case 2: One child (right) */
        else if (root->left == NULL) {
            Node temp = root;
            root = root->right;
            free(temp);
        }
        /* Case 3: One child (left) */
        else if (root->right == NULL) {
            Node temp = root;
            root = root->left;
            free(temp);
        }
        /* Case 4: Two children */
        else {
            Node temp = findLargestNode(root->left);
            root->data = temp->data;
            root->left = deleteNode(root->left, temp->data);
        }
    }
    return root;
}

void inorder(Node root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main() {
    Node root = NULL;

    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);

    printf("Inorder traversal:\n");
    inorder(root);

    printf("\nAfter deleting 10:\n");
    root = deleteNode(root, 10);
    inorder(root);

    return 0;
}
