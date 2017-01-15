#include <bits/stdc++.h>
#define N 1000005
#define PB push_back
#define MP make_pair
#define FF first
#define SS second

const int INF = 1e9 + 7;
using namespace std;

int a[10], b[N], dp[N];
vector < int > vp;

void getprimes() {
    int i, j;
    vp.clear();
    vp.PB(2);
    for(i = 3 ; i < N ; i+=2) {
        if(a[i] == 0) {
            vp.PB(i);
            if(i <= sqrt(N)) {
                for(j = i*i ; j < N ; j+=i) {
                    a[j] = 1;
                }
            }
        }
    }
}

int hasdigits(int num) {
    int n, d;
    n = num;
    while(n > 0) {
        d = n % 10;
        n /= 10;
        if(a[d] == 0)
            return 0;
    }
    return 1;
}

int countdigits(int num) {
    int cnt;
    cnt = 0;
    while(num > 0) {
        num /= 10;
        cnt++;
    }
    return cnt;
}

vector < pair < int, int > > getpfact(int num) {
    int i, f, cnt;
    vector < pair < int, int > > vpf;
    vpf.clear();
    for(i = 0 ; i < vp.size() ; i++) {
        f = vp[i];
        cnt = 0;
        while(num % f == 0) {
            cnt++;
            f *= vp[i];
        }
        if(cnt > 0) {
            vpf.PB(MP(vp[i], cnt));
        }
    }
    return vpf;
} 

vector < int > getpows(int f, int p) {
    vector < int > v;
    int i;
    v.clear();
    for(i = 0 ; i <= p ; i++) {
        v.PB(pow(f, i));
    }
    return v;
}

int getminsteps(int num) {
    int i, j, k;
    // cout << "num=" << num << " ";
    if(dp[num] == 0) {
        if(hasdigits(num)) {
            // cout << "has dig ";
            dp[num] = countdigits(num);
            // cout << dp[num] << endl;
            return dp[num];
        }
        int f;
        vector < pair < int, int > > vpf;
        vector < int > vf[2], vpow;
        vpf = getpfact(num);
        vf[0].clear();
        vf[1].clear();
        f = 0;
        vf[f].PB(1);
        for(i = 0 ; i < vpf.size() ; i++) {
            vpow = getpows(vpf[i].FF, vpf[i].SS);
            vf[f^1].clear();
            for(j = 0 ; j < vpow.size() ; j++) {
                for(k = 0 ; k < vf[f].size() ; k++) {
                    vf[f^1].PB(vpow[j] * vf[f][k]);
                }
            }
                f ^= 1;
        }
        dp[num] = INF;
        for(i = 0 ; i < vf[f].size() ; i++) {
            dp[num] = min(dp[num], getminsteps(vf[f][i]) + getminsteps(num / vf[f][i]) + 1);
        }
    }
    // cout << dp[num] << endl;
    return dp[num]; 
}

int main() {
    int t, h, i, num, ans;
    scanf("%d", &t);
    getprimes();
    h = 0;
    while(t--) {
        h++;
        memset(dp, 0, sizeof(dp));
        for(i = 0 ; i < 10 ; i++) {
            scanf("%d", &a[i]);
        }
        scanf("%d", &num);
        ans = getminsteps(num) + 1;
        if(ans == INF + 1) {
            printf("Case #%d: Impossible\n", h);
        }
        else {
            printf("Case #%d: %d\n", h, ans);
        }
    }
    return 0;
}
