#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} *Node;

Node push(Node top, int ele) {
    Node nn = malloc(sizeof(struct node));
    if (nn == NULL) {
        printf("\nStack Overflow!");
        return top;
    }

    nn->data = ele;
    nn->link = top;
    top = nn;

    printf("\nPushed: %d", ele);
    return top;
}

Node pop(Node top) {
    if (top == NULL) {
        printf("\nStack Underflow!");
        return top;
    }

    Node temp = top;
    printf("\nPopped: %d", temp->data);
    top = top->link;
    free(temp);

    return top;
}

void peek(Node top) {
    if (top == NULL) {
        printf("\nStack is Empty!");
        return;
    }
    printf("\nTop Element: %d", top->data);
}

void display(Node top) {
    if (top == NULL) {
        printf("\nStack is Empty!");
        return;
    }

    printf("\nStack Elements: ");
    for (Node T = top; T != NULL; T = T->link) {
        printf("%d ", T->data);
    }
}

int main() {
    Node top = NULL;

    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    display(top);

    top = pop(top);
    display(top);

    peek(top);

    top = push(top, 40);
    top = push(top, 50);
    display(top);

    return 0;
}
