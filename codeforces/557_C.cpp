#include <bits/stdc++.h>
#define ff first
#define ss second
#define N 100000
#define INF 1000000007
using namespace std;
pair < int, int > p[N];
pair < int , int > q[N];
vector < int > tmp;
bool cmp(pair < int, int > p1, pair < int, int > p2){
	if(p1.ff != p2.ff)
		return (p1.ff > p2.ff);
	return (p1.ss < p2.ss);
}
bool cmp1(pair < int, int > p1, pair < int, int > p2) {
	return (p1.ss < p2.ss);
}
int main(){
	int n, *l, *d, extra, minm, curr, ncurr, delcnt, cnt, ndel, sum, lmax, f, nmax;
	scanf("%d", &n);
	l = new int[n];
	d = new int[n];
	for(int i = 0 ; i < n;  i++)
		scanf("%d", &l[i]);
	for(int i= 0 ; i < n ; i++)
		scanf("%d", &d[i]);
	for(int i = 0 ; i < n ; i++){
		p[i] = make_pair(l[i], d[i]);
		q[i] = make_pair(l[i], d[i]);
	}
	sort(p, p+n, cmp);
	sort(q, q+n, cmp1);
	curr = 0;
	ncurr = n;
	// for(int i = 0 ; i < n ; i++)
	// 	cout << p[i].ff << " " << p[i].ss << endl;
	// cout << "done" << endl;
	// for(int i = 0 ; i < n; i++)
	// 	cout << q[i].ff << " " << q[i].ss << endl;
	// cout << "done1" << endl;
	for(int i = 0 ; i < n ; i++){
		cnt = 1;
		sum = p[i].ss;
		lmax = p[i].ff;
		i++;
		while(i < n && p[i].ff == lmax){
			sum += p[i].ss;
			cnt++;
			i++;
		}
		i--;
		nmax = 2 * cnt - 1;
		extra = 0;
		ndel = ncurr - nmax;
		delcnt = 0;
		// cout << "lmax=" << lmax << " " << cnt << " " << curr << " " << sum << " " << ncurr << " " << nmax << " " << ndel << endl;
		for(int j = 0 ; j < n ; j++){
			if(delcnt == ndel){
				f = 2;
				break;
			}
			if(q[j].ff < lmax){
				extra += q[j].ss;
				delcnt++;
				// cout << "xtra = " << extra  << " ff=" << q[j].ff << endl;
			}
		}
		tmp.push_back(curr+extra);
		// cout << "\ninserted : " << curr+extra << endl << endl;
		curr += sum;
		ncurr -= cnt;
	}
	minm = INF;
	for(int i = 0 ; i < tmp.size() ; i++){
		if(tmp[i] < minm)
			minm = tmp[i];
	}
	printf("%d", minm);
	return 0;
}
