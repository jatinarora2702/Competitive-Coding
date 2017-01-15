#include <bits/stdc++.h>
#define PB push_back
#define N 100005
using namespace std;

vector < int > v;
int pref[N];

void makepref(string a) {
	int i, j;
	pref[0] = -1;
	for(i = 1 ; i < a.size() ; i++) {
		j = i-1;
		while(1) {
			j = pref[j];
			j++;
			if(a[i] == a[j]) {
				pref[i] = j;
				break;
			}
			else if(j == 0) {
				pref[i] = -1;
				break;
			}
			else {
				j--;
			}
		}
	}
}

void kmp(string a, string b) {
	int i, j;
	j = 0;
	for(i = 0 ; i < a.size() ; i++) {
		if(a[i] == b[j]) {
			j++;
			if(j == b.size()) {
				v.PB(i-j+1);
				j = pref[j-1];
				j++;
			}
		}
		else {
			while(j > 0) {
				j = pref[j-1];
				j++;
				if(a[i] == b[j]) {
					j++;
					break;
				}
			}
		}
	}
}

int main() {
	int i;
	string a, b;
	cin >> a >> b;
	// a = "AABAACAADAABAAABAA";
	// b = "AABA";
	makepref(b);
	kmp(a, b);
	for(i = 0 ; i < v.size() ; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
	return 0;
}