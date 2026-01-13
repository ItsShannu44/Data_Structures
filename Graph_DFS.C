#include <stdio.h>
#include <stdlib.h>

struct node {
    int vertex;
    struct node* next;
};

struct graph {
    int V;
    struct node** adj;
};

int visited[10];

struct graph* createGraph(int V) {
    struct graph* g = (struct graph*)malloc(sizeof(struct graph));
    g->V = V;
    g->adj = (struct node**)malloc(V * sizeof(struct node*));

    for (int i = 0; i < V; i++)
        g->adj[i] = NULL;

    return g;
}

void addEdge(struct graph* g, int src, int dest) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->vertex = dest;
    temp->next = g->adj[src];
    g->adj[src] = temp;
}

void DFS(struct graph* g, int v) {
    visited[v] = 1;
    printf("%d ", v);

    struct node* temp = g->adj[v];
    while (temp) {
        if (!visited[temp->vertex])
            DFS(g, temp->vertex);
        temp = temp->next;
    }
}

int main() {
    struct graph* g = createGraph(4);

    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);

    printf("DFS Traversal: ");
    DFS(g, 0);

    return 0;
}
