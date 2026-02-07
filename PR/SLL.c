#include <stdio.h>
#include <stdlib.h>

typedef struct Mynode {
    int data;
    struct Mynode *link;
} *Node;


Node Create_Node(int value) {
    Node nn = (Node)malloc(sizeof(struct Mynode));
    if (nn == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    nn->data = value;
    nn->link = NULL;
    return nn;
}

Node Insert_Front(Node H, int value) {
    Node nn = Create_Node(value);
    if (nn == NULL)
        return H;

    nn->link = H;
    return nn;
}

Node Insert_Rear(Node H, int value) {
    Node nn = Create_Node(value);
    if (nn == NULL)
        return H;

    if (H == NULL) {
        return nn;
    }

    Node T = H;
    while (T->link != NULL) {
        T = T->link;
    }

    T->link = nn;
    printf("Inserted %d at Rear\n", nn->data);
    return H;
}

void Display(Node H) {
    if (H == NULL) {
        printf("List is empty\n");
        return;
    }

    for (Node T = H; T != NULL; T = T->link) {
        printf("%d -> ", T->data);
    }
    printf("NULL\n");
}

int main() {
    Node H = NULL;

    H = Insert_Front(H, 10);
    H = Insert_Front(H, 20);
    H = Insert_Front(H, 30);

    Display(H);

    H = Insert_Rear(H, 50);
    Display(H);

    return 0;
}
