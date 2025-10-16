#include <stdio.h>
#include <stdlib.h>
#define INF 1000000

int minKey(int key[], int mstSet[], int n) {
    int min = INF, min_index = -1;
    for(int v=0; v<n; v++)
        if(mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    return min_index;
}

int main() {
    int n, start;
    FILE *f = fopen("inUnAdjMat.dat", "r");
    if(!f) {
        printf("Error opening file\n");
        return 1;
    }
    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);
    int graph[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            fscanf(f, "%d", &graph[i][j]);
    fclose(f);

    printf("Enter the Starting Vertex: ");
    scanf("%d", &start);
    start--;

    int parent[n], key[n], mstSet[n];
    for(int i=0; i<n; i++) {
        key[i] = INF;
        mstSet[i] = 0;
        parent[i] = -1;
    }
    key[start] = 0;

    for(int count=0; count<n-1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;
        for(int v=0; v<n; v++) {
            if(graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int mst[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            mst[i][j] = 0;

    int total = 0;
    for(int i=0; i<n; i++) {
        if(parent[i] != -1) {
            mst[i][parent[i]] = graph[i][parent[i]];
            mst[parent[i]][i] = graph[i][parent[i]];
            total += graph[i][parent[i]];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            printf("%d ", mst[i][j]);
        printf("\n");
    }
    printf("Total Weight of the Spanning Tree: %d\n", total);

    return 0;
}
