#include <stdio.h>
#include <stdlib.h>

typedef mynode {
    int data;
    Mynode *left, *right;
}*Mynode;


Mynode newNode(int val) {
    Mynode temp = malloc(sizeof(mynode));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}
Mynode* insert(Mynode root, int val) {
    if (root == NULL)
        return newNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

void inorder(Mynode root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(Mynode root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(Mynode root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
int main() {
    Mynode root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    printf("Inorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);


    return 0;
}


