#include <stdio.h>

int main() {
    int v, e;
    scanf("%d %d", &v, &e);

    int adj[v][v];

    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            adj[i][j] = 0;

    for (int i = 0; i < e; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }

    return 0;
}
