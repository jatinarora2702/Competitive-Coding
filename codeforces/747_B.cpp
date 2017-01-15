#include <bits/stdc++.h>
#define FF first
#define SS second
using namespace std;

int main() {
	int n, i, cnt, f, tmp;
	pair < char, int > arr[4];
	string s;
	scanf("%d", &n);
	cin >> s;
	cnt = 0;
	arr[0].SS = 'A';
	arr[1].SS = 'T';
	arr[2].SS = 'G';
	arr[3].SS = 'C';
	for(i = 0 ; i < 4 ; i++) {
		arr[i].FF = 0;
	}
	for(i = 0 ; i < n ; i++) {
		if(s[i] == 'A')
			(arr[0].FF)++;
		else if(s[i] == 'T')
			(arr[1].FF)++;
		else if(s[i] == 'G')
			(arr[2].FF)++;
		else if(s[i] == 'C')
			(arr[3].FF)++;
		else
			cnt++;
	}
	sort(arr, arr+4);
	tmp = arr[3].FF - arr[0].FF;
	tmp += arr[3].FF - arr[1].FF;
	tmp += arr[3].FF - arr[2].FF;
	f = 0;
	if((cnt-tmp)%4 == 0 && cnt-tmp >= 0) {
		for(i = 0 ; i < n ; i++) {
			if(s[i] == '?') {
				if(arr[3].FF - arr[0].FF > 0) {
					s[i] = arr[0].SS;
					(arr[0].FF)++;
				}
				else if(arr[3].FF - arr[1].FF > 0) {
					s[i] = arr[1].SS;
					(arr[1].FF)++;
				}
				else if(arr[3].FF - arr[2].FF > 0) {
					s[i] = arr[2].SS;
					(arr[2].FF)++;
				}
				else {
					switch(f) {
						case 0: s[i] = 'A';
								break;
						case 1: s[i] = 'T';
								break;
						case 2: s[i] = 'G';
								break;
						case 3: s[i] = 'C';
								break;
					}
					f++;
					f %= 4;
				}
			}
		}
		cout << s << endl;
	}
	else {
		printf("===\n");
	}
	return 0;
}