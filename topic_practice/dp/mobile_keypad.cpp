#include <bits/stdc++.h>
using namespace std;
#define N 100
#define PB push_back

vector < int > v[10];
int dp[N][10];

void init() {
    int j;
    v[0].PB(8); v[0].PB(0);
    v[1].PB(2); v[1].PB(4); v[1].PB(1);
    v[2].PB(1); v[2].PB(3); v[2].PB(5); v[2].PB(2);
    v[3].PB(2); v[3].PB(6); v[3].PB(3);
    v[4].PB(1); v[4].PB(5); v[4].PB(7); v[4].PB(4);
    v[5].PB(2); v[5].PB(4); v[5].PB(6); v[5].PB(8); v[5].PB(5);
    v[6].PB(3); v[6].PB(5); v[6].PB(9); v[6].PB(6);
    v[7].PB(4); v[7].PB(8); v[7].PB(7);
    v[8].PB(5); v[8].PB(7); v[8].PB(9); v[8].PB(0); v[8].PB(8);
    v[9].PB(6); v[9].PB(8); v[9].PB(9);
    for(j = 0 ; j < 10 ; j++) {
        dp[j][0] = 1;
        cout << dp[j][0] << " ";
    }
    cout << endl;
}

int main() {
    int n, i, j, k, sum;
    scanf("%d", &n);
    init();
    for(i = 1 ; i < n ; i++) {
        for(j = 0 ; j < 10 ; j++) {
            dp[j][i] = 0;
            for(k = 0 ; k < v[j].size() ; k++) {
                dp[j][i] += dp[v[j][k]][i-1];
            }
            cout << dp[j][i] << " ";
        }
        cout << endl;
    }
    sum = 0;
    for(j = 0 ; j < 10 ; j++) {
        sum += dp[j][n-1];
    }
    printf("%d\n", sum);
    return 0;
}
