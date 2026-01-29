#include <stdio.h>
#include <stdlib.h>

typedef struct mynode {
    int data;
    struct mynode *left, *right;
} *Mynode;

Mynode newNode(int val) {
    Mynode temp = (Mynode)malloc(sizeof(struct mynode));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}
Mynode insert(Mynode root, int val) {
    if (root == NULL)
        return newNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}


Mynode findLargestNode(Mynode root) {
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}


Mynode deleteNode(Mynode root, int key) {

    if (root == NULL) {
        printf("Item not found in tree\n");
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        /* Leaf node */
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        /* Only right child */
        else if (root->left == NULL) {
            Mynode temp = root;
            root = root->right;
            free(temp);
        }
        /* Only left child */
        else if (root->right == NULL) {
            Mynode temp = root;
            root = root->left;
            free(temp);
        }
        /* Two children */
        else {
            Mynode temp = findLargestNode(root->left);
            root->data = temp->data;
            root->left = deleteNode(root->left, temp->data);
        }
    }

    return root;
}

int main() {
    Mynode root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    root = deleteNode(root, 50);

    return 0;
}
