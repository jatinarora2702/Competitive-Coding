#include <bits/stdc++.h>
#define N 200005
using namespace std;

typedef long long ll;

const ll INF = 1e16 + 7LL;

vector < int > v[N];

int main() {
    int n, k, x;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> x;
        int cnt = 0;
        while(x > 0) {
            v[x].push_back(cnt);
            x /= 2;
            cnt++;
        }
    }
    ll minm = INF;
    for(int i = 0; i < N; i++) {
        if(v[i].size() < k) {
            continue;
        }
        sort(v[i].begin(), v[i].end());
        ll s = 0;
        for(int j = 0; j < k; j++) {
            s += v[i][j];
        }
        minm = min(minm, s);
    }
    cout << minm << "\n";
    return 0;
}