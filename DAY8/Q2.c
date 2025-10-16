#include <stdio.h>
#include <string.h>

int main() {
    char a[100], b[100], lcs[100];
    int m, n, i, j;
    printf("Enter the first string into an array: ");
    scanf("%s", a);
    printf("Enter the second string into an array: ");
    scanf("%s", b);
    m = strlen(a);
    n = strlen(b);
    int dp[m+1][n+1];
    for(i = 0; i <= m; i++) {
        for(j = 0; j <= n; j++) {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];
        }
    }
    int index = dp[m][n];
    lcs[index] = '\0';
    i = m; j = n;
    while(i > 0 && j > 0) {
        if(a[i-1] == b[j-1]) {
            lcs[index-1] = a[i-1];
            i--; j--; index--;
        } else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    printf("LCS: %s\n", lcs);
    printf("LCS Length: %d\n", dp[m][n]);
    return 0;
}
