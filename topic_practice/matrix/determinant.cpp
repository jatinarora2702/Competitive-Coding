#include <bits/stdc++.h>
#define N 100
using namespace std;
int a[N][N];
void cofact(int a[][N], int temp[][N], int n, int p, int q){
    int i1, j1;
    i1 = j1 = 0;
    for(int i = 0 ; i < n ; i++){
        if(i == p)
            continue;
        for(int j = 0 ; j < n ; j++){
            if(j == q)
                continue;
            temp[i1][j1++] = a[i][j];
        }
        i1++;
        j1 = 0;
    }
}
int getdet(int a[][N], int n){
    if(n == 1)
        return a[0][0];
    int ans, f, temp[N][N];
    f = 1;
    ans = 0;
    for(int i = 0 ; i < n ; i++){
        cofact(a, temp, n, 0, i);
        ans += a[0][i] * f * getdet(temp, n-1);
        f = -f;
    }
    return ans;
}
int main(){
    int n, ans;
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            scanf("%d", &a[i][j]);
        }
    }
    ans = getdet(a, n);
    printf("det: %d\n", ans);
    return 0;
}