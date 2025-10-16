#include <stdio.h>
#include <limits.h>

int main() {
    int n, i, j, k, l, q;
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    int r[n], c[n];
    for(i = 0; i < n; i++) {
        printf("Enter row and col size of A%d: ", i+1);
        scanf("%d %d", &r[i], &c[i]);
        if(i > 0 && r[i] != c[i-1]) {
            printf("Invalid matrix dimensions\n");
            return 0;
        }
    }
    int m[n][n], s[n][n];
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            m[i][j] = 0;
            s[i][j] = 0;
        }
    }
    for(l = 2; l <= n; l++) {
        for(i = 0; i <= n-l; i++) {
            j = i + l - 1;
            m[i][j] = INT_MAX;
            for(k = i; k < j; k++) {
                q = m[i][k] + m[k+1][j] + r[i]*c[k]*c[j];
                if(q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("M Table:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(j < i)
                printf("0 ");
            else
                printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    printf("S Table:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(j <= i)
                printf("0 ");
            else
                printf("%d ", s[i][j]+1);
        }
        printf("\n");
    }
    void printpar(int s[][n], int i, int j) {
        if(i == j)
            printf("A%d", i+1);
        else {
            printf("(");
            printpar(s, i, s[i][j]);
            printpar(s, s[i][j]+1, j);
            printf(")");
        }
    }
    printf("Optimal parenthesization: ");
    printpar(s, 0, n-1);
    printf("\nThe optimal ordering of the given matrices requires %d scalar multiplications.\n", m[0][n-1]);
    return 0;
}
