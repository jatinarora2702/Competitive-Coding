#include <bits/stdc++.h>
#define f first
#define s second
#define MAX 200005
using namespace std;
typedef unsigned long long int ulli;
int n, m;
ulli *br, *brmin, *brmax;
vector < int > final(MAX);
int getans(vector < int > used, int k){
	// cout << "used : ";
	// for(int i = 0 ; i < m ; i++)
	// 	cout << used[i] << " ";
	// cout << endl;
	if(k == n-1){
		final = used;
		return 1;
	}
	for(int j = 0 ; j < m ; j++){
		if(used[j] == -1 and br[j] >= brmin[k] and br[j] <= brmax[k]){
			used[j] = k;
			if(getans(used, k+1) == 1)
				return 1;
			used[j] = -1;
		}
	}
	// cout << "k=" << k << endl;
	return 0;
}
void print(ulli *a, int n){
	for(int i = 0 ; i < n ; i++)
		cout << a[i] << " ";
	cout << endl;
}
int main() {
	scanf("%d%d", &n, &m);
	vector < pair < ulli, ulli > > land(n);
	brmin = new ulli[n];
	brmax = new ulli[n];
	br = new ulli[m];
	vector < int > used(m, -1);
	for(int i = 0 ; i < n ; i++){
		cin >> land[i].f >> land[i].s;
	}
	//cout << "qq\n";
	for(int i = 0 ; i < m ; i++){
		cin >> br[i];
	}
	//cout << "re1\n";
	for(int i = 0 ; i < n-1 ; i++){
		brmin[i] = -(ulli)land[i].s + (ulli)land[i+1].f;
		brmax[i] = -(ulli)land[i].f + (ulli)land[i+1].s;
	}
	// cout << "mins :\n";
	// print(brmin, n);
	// cout << "maxs :\n";
	// print(brmax, n);

	//cout << "reached" << endl;
	if(getans(used, 0) == 1){
		printf("Yes\n");
		int *ans = new int[n];
		// cout << "used array :\n";
		// for(int i = 0 ; i < m ; i++)
		// 	cout << used[i] << " ";
		// cout << endl;
		for(int i = 0 ; i < m ; i++){
			if(final[i] != -1)
				ans[final[i]] = i+1;
		}
		for(int i = 0 ; i < n-1 ; i++)
			printf("%d ", ans[i]);
	}
	else
		printf("No");
	return 0;
}