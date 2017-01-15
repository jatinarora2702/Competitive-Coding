#include <bits/stdc++.h>
#define N 100005
using namespace std;
typedef long long int lli;
const lli INF = 1e18;
string a[N], b[N];
int c[N];
lli ans1[N], ans2[N];
int main() {
   int n, i;
   scanf("%d", &n);
   for(i = 0 ; i < n ; i++) {
      scanf("%d", &c[i]);
   }
   for(i = 0 ; i < n ; i++) {
      cin >> b[i];
      a[i] = b[i];
      reverse(b[i].begin(), b[i].end());
   }
   ans1[0] = 0;
   ans2[0] = c[0];
   for(i = 1 ; i < n ; i++) {
      ans1[i] = ans2[i] = INF;
      if(a[i] >= a[i-1])
         ans1[i] = ans1[i-1];
      if(a[i] >= b[i-1])
         ans1[i] = min(ans1[i], ans2[i-1]);
      if(b[i] >= a[i-1])
         ans2[i] = ans1[i-1] + c[i];
      if(b[i] >= b[i-1])
         ans2[i] = min(ans2[i], ans2[i-1] + c[i]);
   }
   cout << ((min(ans1[n-1], ans2[n-1]) < INF) ? min(ans1[n-1], ans2[n-1]) : -1) << "\n";
   return 0;
}
   
