#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair

using namespace std;

#define N 25

char a[N][N];
int used[N][N], r, c;
float p, q;

float getans(int xi, int xj, int k);

int isvalid(int xi, int xj) {
	if(xi >= 0 && xi < r && xj >= 0 && xj < c)
		return 1;
	return 0;
}

float eval(int xi, int xj, int k) {
	float s;
	s = 0.0;
	if(isvalid(xi, xj)) {
		s += ((a[xi][xj] == 'A') ? (1.0-q) : (1.0-p)) * (getans(xi, xj, k));			
		used[xi][xj] = 1;
		s += ((a[xi][xj] == 'A') ? q : p) * (1.0 + getans(xi, xj, k));
		used[xi][xj] = 0;
	}
	return s;
}

float getans(int xi, int xj, int k) {
	float ans;	
	ans = 0.0;
	if(isvalid(xi, xj) && k > 0) {
		ans += 0.25 * eval(xi+1, xj, k-1);
		ans += 0.25 * eval(xi-1, xj, k-1);
		ans += 0.25 * eval(xi, xj+1, k-1);
		ans += 0.25 * eval(xi, xj-1, k-1);		
	}
	return ans;
}

int main() {
	int t, i, j, rs, cs, s, h;
	float ans;
	scanf("%d", &t);
	h = 0;
	while(t--) {
		h++;
		scanf("%d%d%d%d%d", &r, &c, &rs, &cs, &s);
		scanf("%f%f", &p, &q);	
		for(i = 0 ; i < r ; i++) { 
			for(j = 0 ; j < c ; j++) {
				scanf("%c", &a[i][j]);
			}		
		}	
		for(i = 0 ; i < r ; i++) {
			for(j = 0 ; j < c ; j++) {
				used[i][j] = 0;
			}
		}
		ans = getans(rs, cs, s);
		cout << "Case #" << h << ": " << ans << endl;
	}		
}