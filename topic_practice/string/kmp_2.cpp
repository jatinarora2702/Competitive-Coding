#include <bits/stdc++.h>
#define N 10000
#define PB push_back
using namespace std;

vector < int > v;
string s, pt;
int prefix[N];

void getprefix() {
	int i, j, k;
	prefix[0] = -1;
	for(i = 1 ; i < pt.size() ; i++) {
		prefix[i] = -1;
		j = i-1;
		while(j >= 0) {
			k = prefix[j] + 1;
			if(pt[i] == pt[k]) {
				prefix[i] = k;
				break;
			}
			j = k-1;
		}
	}
}

int main() {
	int n, i, j;
	getline(cin, s);
	getline(cin, pt);
	getprefix();
	j = 0;
	for(i = 0 ; i < s.size() ; i++) {
		if(s[i] == pt[j]) {
			j++;
			if(j == pt.size()) {
				v.PB(i-pt.size()+1);
				j = prefix[j-1];
				j++;
			}
		}
		else {
			while(j > 0) {
				j = prefix[j-1];
				j++;
				if(s[i] == pt[j]) {
					j++;
					break;
				}
			}
		}
	}
	for(i = 0 ; i < v.size() ; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
	return 0;
}