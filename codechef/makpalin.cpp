#include <bits/stdc++.h>
#define N 100005
using namespace std;
int pal[N], k, m;
int palin(char s[], int l, int r, int k){
	if(r - l <= 0){
		cout << "l=" << l << " r=" << r << " k=" << k << " str=";
		for(int i = l ; i <= r ; i++)
			cout << s[i];
		cout << " | pal=";
		
		pal[k] = 1;
		m = k;
		cout << pal[k] << " | yy\n";
		return 1;
	}
	int k1 = palin(s, l+1, r-1, k+1);
	cout << "l=" << l << " r=" << r << " k=" << k << " str=";
	for(int i = l ; i <= r ; i++)
		cout << s[i];
	cout << " | pal=";
	if(s[l] == s[r]){
		pal[k] = k1;
	}
	else{
		pal[k] = 0;
		// cout << "kk\n";
	}
	cout << pal[k] << endl;
	return pal[k];
}
int checkpalin(vector < char > v){
	int i, j, n;
	n = v.size();
	i = 0;
	j = n-1;
	while(i < j){
		if(v[i] != v[j])
			return 0;
		i++;
		j--;
	}
	return 1;
}
int brute(char s[], int n){
	int cnt = 0;
	vector < char > v, v1;
	v.assign(s, s+n);
	for(int i = 0 ; i <= n ; i++){
		v1 = v;
		char c = v[n-i-1];
		if(i > n/2)
			c = v[n-i];
		// cout << "i=" << i << " ";
		v1.insert(v1.begin()+i, c);
		if(checkpalin(v1)){
			// cout << "yy";
			cnt++;
		}
		// cout << "\n";
	}
	return cnt;
}
int main(){
	int t, n, cnt, i, j;
	char s[N];
	scanf("%d", &t);
	while(t--){
		scanf("%s", s);
		for(n = 0 ; s[n] != '\0' ; n++);
		// if(n  <= 1000){
		// 	cnt = brute(s, n);
		// 	printf("%d\n", cnt);
		// 	continue;
		// }
		k = 0;
		m = 0;
		palin(s, 0, n-2, 0);
		// for(i = 0 ; i <= m ; i++){
		// 	cout << pal[i] << " p " << endl;
		// }
		cnt = 0;
		i = 0;
		cout << "m=" << m << endl;
		while(i <= m){
			// cout << "tt\n";
			if(pal[i] == 1){
				if(i == 0 || (n-i >= 0 && (s[i-1] == s[n-i])))
					cnt++;
				else
					break;
				i++;
			}
			else{
				// cout << "uu\n";
				if(s[i] != s[n-i-1])
					break;
				i++;
			}
		}
		k = 0;
		m = 0;
		cout << "cnt1=" << cnt << endl;
		palin(s, 1, n-1, 0);
		cout << "m=" << m << endl;
		// for(i = 0 ; i <= m ; i++){
		// 	cout << pal[i] << " p1 " << endl;
		// }
		i = 0;
		while(i <= m){
			if(pal[i] == 1){
				if(i == 0 || (n-i >= 0 && (s[i-1] == s[n-i])))
					cnt++;
				i++;
			}
			else{
				if(s[i] != s[n-i-1])
					break;
				i++;
			}
		}
		// cout << "cnt=" << cnt << endl;
		if(n % 2 == 0){
			int k2 = palin(s, 0, n-1, 0);
			if(k2 == 1)
				cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}