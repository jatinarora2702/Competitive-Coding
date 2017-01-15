#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define N 6000
using namespace std;
pair < int, int > p[N];
vector < int > v;
int dp[N], s[N];
void merges(pair < int, int > a[N], int keya[], int m, pair < int, int > b[N], int keyb[], int n, pair < int, int > c[N], int keyc[]){
	int i, j, k;
	i = j = k = 0;
	while(i < m && j < n){
		if(a[i].FF < b[j].FF){
			c[k] = a[i];
			keyc[k] = keya[i];
			k++;
			i++;
		}
		else if(a[i].FF > b[j].FF){
			c[k] = b[j];
			keyc[k] = keyb[j];
			k++;
			j++;
		}
		else if(a[i].SS < b[j].SS){
			c[k] = a[i];
			keyc[k] = keya[i];
			k++;
			i++;	
		}
		else{
			c[k] = b[j];
			keyc[k] = keyb[j];
			k++;
			j++;	
		}
	}
	while(i < m){
		c[k] = a[i];
		keyc[k] = keya[i];
		k++;
		i++;
	}
	while(j < n){
		c[k] = b[j];
		keyc[k] = keyb[j];
		k++;
		j++;
	}
}
void merge_sort(pair < int, int > p1[], int key1[], int n){
	if(n == 1){
		key1[0] = 0;
		return;
	}
	int mid = n / 2;
	pair < int, int > q[N];
	int key2[N], key3[N];
	merge_sort(p1, key2, mid);
	merge_sort(p1+mid, key3, n-mid);
	for(int i = 0 ; i < n-mid ; i++)
		key3[i] = key3[i] + mid;
	// cout << "key2:";
	// for(int i = 0 ; i < mid ; i++)
	// 	cout << key2[i] << " ";
	// cout << "\nkey3:";
	// for(int i = 0 ; i < n-mid ; i++)
	// 	cout << key3[i] << " ";
	// cout << "\n";
	merges(p1, key2, mid, p1+mid, key3, n-mid, q, key1);
	// cout << "q arr:" << endl;
	for(int i = 0 ; i < n ; i++){
		// cout << "[" << q[i].FF << " " << q[i].SS << "]";
		p1[i].FF = q[i].FF;
		p1[i].SS = q[i].SS;
	}
	// cout << endl << "keys: ";
	// for(int i = 0 ; i < n ; i++){
	// 	cout << key1[i] << " ";
	// }
	// cout << endl << "done" << endl;
}
int main(){
	int n, w, h, maxm, k, key[N];
	scanf("%d%d%d", &n, &w, &h);
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d", &p[i].FF, &p[i].SS);
	}
	for(int i = 0 ; i < n ; i++)
		key[i] = i;
	merge_sort(p, key, n);
	// for(int i = 0 ; i < n; i++){
	// 	printf("(%d, %d), ", p[i].FF, p[i].SS);
	// }
	// printf("\n");
	for(int i = 0 ; i < n ; i++){
		if(p[i].FF > w && p[i].SS > h){
			dp[i] = 0;
			s[i] = -1;
			for(int j = 0 ; j < i ; j++){
				if(dp[j] > dp[i] && p[j].FF < p[i].FF && p[j].SS < p[i].SS){
					dp[i] = dp[j];
					s[i] = j;
				}
			}
			dp[i]++;
		}
		else{
			dp[i] = -1;
			s[i] = -1;
		}
	}
	maxm = -1;
	k = -1;
	for(int i = 0 ; i < n ; i++){
		if(maxm < dp[i]){
			maxm = dp[i];
			k = i;
		}
	}
	if(maxm == -1)
		printf("0");
	else{
		printf("%d\n", maxm);
		while(k != -1){
			v.PB(key[k]+1);
			k = s[k];
		}
		for(int i = v.size()-1 ; i >= 0 ; i--)
			printf("%d ", v[i]);
	}
	return 0;
}