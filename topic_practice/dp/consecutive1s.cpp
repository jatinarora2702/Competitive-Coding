#include <bits/stdc++.h>
#define N 10005
using namespace std;

int dp[2][N];

int main() {
    int i, n;
    scanf("%d", &n);
    dp[0][0] = dp[1][0] = 1;
    for(i = 1 ; i < n ; i++) {
        dp[0][i] = dp[0][i-1] + dp[1][i-1];
        dp[1][i] = dp[0][i-1];
    }
    printf("%d\n", dp[0][n-1] + dp[1][n-1]);
    return 0;
}
