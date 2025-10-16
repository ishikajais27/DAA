#include <stdio.h>
#include <stdlib.h>

#define INF 1000000

int main() {
    int n, i, j, k, u, v;
    FILE *f = fopen("inDiAdjMat2.dat", "r");
    if(!f) {
        printf("Error opening file\n");
        return 1;
    }
    printf("Number of Vertices: ");
    scanf("%d", &n);
    int dist[n][n], path[n][n];

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            fscanf(f, "%d", &dist[i][j]);
            if(i != j && dist[i][j] == 0)
                dist[i][j] = INF;
            path[i][j] = -1;
        }
    }
    fclose(f);

    for(k=0; k<n; k++) {
        for(i=0; i<n; i++) {
            for(j=0; j<n; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = k;
                }
            }
        }
    }

    printf("Enter the source and destination vertex: ");
    scanf("%d %d", &u, &v);
    u--; v--;

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    void printPath(int p[n][n], int i, int j) {
        if(p[i][j] == -1)
            return;
        printPath(p, i, p[i][j]);
        printf("-->%d", p[i][j] + 1);
        printPath(p, p[i][j], j);
    }

    printf("Shortest Path from vertex %d to vertex %d: %d", u+1, v+1, u+1);
    printPath(path, u, v);
    printf("-->%d\n", v+1);
    printf("Path weight: %d\n", dist[u][v]);
    return 0;
}
