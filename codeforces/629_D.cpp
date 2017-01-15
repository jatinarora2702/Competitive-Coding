#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define N 100005
using namespace std;
typedef long long int lli;
typedef long double ld;
const int MOD = 1e9+7;
const int INF = 1e9+7;
const double pi = atan(1.0) * 4.0;
pair < int, int > p[N];
vector < lli > vol(N, 0), lis(N, 0);

void find_lis(vector<lli> &a, vector<lli> &b)
{
	vector<int> p(a.size());
	int u, v;
 
	if (a.empty()) return;
 
	b.push_back(0);
 
	for (size_t i = 1; i < a.size(); i++) 
        {
                // If next element a[i] is greater than last element of
                // current longest subsequence a[b.back()], just push it at back of "b" and continue
		if (a[b.back()] < a[i]) 
                {
			p[i] = b.back();
			b.push_back(i);
			continue;
		}
 
                // Binary search to find the smallest element referenced by b which is just bigger than a[i]
                // Note : Binary search is performed on b (and not a).
                // Size of b is always <=k and hence contributes O(log k) to complexity.    
		for (u = 0, v = b.size()-1; u < v;) 
                {
			int c = (u + v) / 2;
			if (a[b[c]] < a[i]) u=c+1; else v=c;
		}
 
                // Update b if new value is smaller then previously referenced value 
		if (a[i] < a[b[u]]) 
                {
			if (u > 0) p[i] = b[u-1];
			b[u] = i;
		}	
	}
 
	for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
}

int main(){
	int n;
	lli sum;
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d", &p[i].FF, &p[i].SS);
	}
	for(int i = 0 ; i < n ; i++){
		vol[i] = (lli)p[i].FF * (lli)p[i].FF * (lli)p[i].SS;
	}
	find_lis(vol, lis);
	sum = 0;
	for(int i = 0 ; i < lis.size() ; i++){
		sum += vol[lis[i]];
	}
	ld ans;
	ans = sum * (ld)pi;
	cout << sum << endl;
}