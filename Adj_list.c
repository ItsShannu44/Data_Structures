#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* n = malloc(sizeof(struct Node));
    n->vertex = v;
    n->next = NULL;
    return n;
}

int main() {
    int v, e;
    scanf("%d %d", &v, &e);

    struct Node* adj[v];
    for (int i = 0; i < v; i++) adj[i] = NULL;

    for (int i = 0; i < e; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        struct Node* n1 = createNode(b);
        n1->next = adj[a];
        adj[a] = n1;

        struct Node* n2 = createNode(a);
        n2->next = adj[b];
        adj[b] = n2;
    }

    for (int i = 0; i < v; i++) {
        printf("%d -> ", i);
        struct Node* temp = adj[i];
        while (temp) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}
