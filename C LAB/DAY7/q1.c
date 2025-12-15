#include <stdio.h>
#include <stdlib.h>
#define INF 1000000

int minDistance(int dist[], int visited[], int n) {
    int min = INF, min_index = -1;
    for(int v=0; v<n; v++) {
        if(!visited[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printPath(int parent[], int j) {
    if(parent[j] == -1) {
        printf("%d", j+1);
        return;
    }
    printPath(parent, parent[j]);
    printf("->%d", j+1);
}

int main() {
    int n, src;
    FILE *f = fopen("inDiAdjMat1.dat", "r");
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

    printf("Enter the Source Vertex: ");
    scanf("%d", &src);
    src--;

    int dist[n], visited[n], parent[n];
    for(int i=0; i<n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }
    dist[src] = 0;

    for(int count=0; count<n-1; count++) {
        int u = minDistance(dist, visited, n);
        if(u == -1) break; // no reachable vertex left
        visited[u] = 1;
        for(int v=0; v<n; v++) {
            if(!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("Source Destination Cost Path\n");
    for(int i=0; i<n; i++) {
        printf("%d %d ", src+1, i+1);
        if(dist[i] == INF) {
            printf("INF -\n");
            continue;
        }
        printf("%d ", dist[i]);
        if(i == src) printf("-\n");
        else printPath(parent, i), printf("\n");
    }

    return 0;
}
