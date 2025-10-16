#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

int cmp(const void *a, const void *b) {
    Edge *x = (Edge*)a;
    Edge *y = (Edge*)b;
    return x->w - y->w;
}

int find(int parent[], int i) {
    if(parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

void unionSet(int parent[], int rank[], int x, int y) {
    int rx = find(parent, x);
    int ry = find(parent, y);
    if(rank[rx] < rank[ry])
        parent[rx] = ry;
    else if(rank[ry] < rank[rx])
        parent[ry] = rx;
    else {
        parent[ry] = rx;
        rank[rx]++;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Edge edges[m];
    for(int i=0; i<m; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    qsort(edges, m, sizeof(Edge), cmp);

    int parent[n+1], rank[n+1];
    for(int i=1; i<=n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int count = 0, total = 0;
    printf("Edge Cost\n");
    for(int i=0; i<m && count < n-1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        int setU = find(parent, u);
        int setV = find(parent, v);
        if(setU != setV) {
            printf("%d--%d %d\n", u, v, w);
            unionSet(parent, rank, setU, setV);
            total += w;
            count++;
        }
    }
    printf("Total Weight of the Spanning Tree: %d\n", total);
    return 0;
}
