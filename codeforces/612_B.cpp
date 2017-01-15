#include <bits/stdc++.h>
#define N 200005
using namespace std;
typedef long long int lli;
int a[N], b[N];
int main(){
	int n, pos;
	lli cnt;
	scanf("%d", &n);
	cnt = 0;
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0 ; i < n ; i++){
		b[a[i]] = i+1;
	}
	pos = b[1];
	// for(int i = 1 ; i <= n ; i++)
	// 	cout << b[i] << " ";
	// cout << endl;
	for(int i = 1 ; i <= n ; i++){
		// cout << "p:" << abs(pos - b[i]) << endl;
		cnt += (lli)(abs(pos - b[i]));
		pos = b[i];
	}
	cout << cnt;
	return 0;
}