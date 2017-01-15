#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int l[N], r[N], a[N], tmp[N], cnt[N], fen[N], n;
void update(int index, int val){
	for(int i = index+1 ; i <= N ; i+= (i & (-i)))
		fen[i] += val;
}
int get_sum(int index){
	int ans = 0;
	for(int i = index ; i > 0 ; i-= (i & (-i)))
		ans += fen[i];
	return ans;
}
int sum(int left, int right){
	return get_sum(right) - get_sum(left);
}
int main(){
	int sz;
	sz = 0;
	scanf("%d", &n);
	for(int i= 0 ; i <  N ; i++)
		fen[i] = 0;
	for(int i = 0 ; i < n ; i++, sz++){
		scanf("%d", &a[i]);
		tmp[i] = a[i];
	}
	// for(int i = 0 ; i < n ; i++)
	// 	cout << tmp[i] << " ";
	// cout << endl;
	sort(tmp, tmp+n);
	sz = unique(tmp, tmp + n) - tmp;
	// cout << "done1\n";
	// for(int i = 0; i < sz ; i++)
	// 	cout << tmp[i] << " ";
	// cout << endl;
	for(int i = 0 ; i < n ; i++)
		a[i] = lower_bound(tmp, tmp+sz, a[i]) - tmp;
	// for(int i = 0 ; i < n ; i++)
	// 	cout << a[i] << " ";
	// cout << endl;
	memset(cnt, 0, sizeof cnt);
	for(int i = 0 ; i < n ; i++){
		cnt[a[i]]++;
		l[i] = cnt[a[i]];
	}
	// for(int i = 0 ; i < n ; i++)
	// 	cout << l[i] << " ";
	// cout << endl;
	// cout << "domne\n";
	memset(cnt, 0, sizeof cnt);
	for(int i = n-1 ; i >= 0 ; i--){
		cnt[a[i]]++;
		r[i] = cnt[a[i]];
		update(r[i], 1);
	}
	// for(int i = 0 ; i < n ; i++)
	// 	cout << r[i] << " ";
	// cout << endl;
	// cout << "apapa\n";
	// for(int i =0 ;  i < n ; i++){
	// 	cout << fen[i] << " ";
	// }
	//cout << endl;
	int ans = 0;
	for(int i = 0 ; i < n ; i++){
		update(r[i], -1);
		//cout << sum(1, l[i]) << " "; 
		ans += sum(1,l[i]);
	}
	printf("%d", ans);
	return 0;
}