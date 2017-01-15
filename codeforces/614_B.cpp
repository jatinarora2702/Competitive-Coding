#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define N 1000005
using namespace std;
typedef long long int lli;
typedef pair < int, int > pii;
const int MOD = 1e9+7;

char s[N], qs[N], ss[N];
int main(){
	int n, f, flag, m, k, flagger;
	scanf("%d", &n);
	k = 0;
	flagger = 0;
	m = 0;
	for(int i = 0 ; i < n ; i++){
		scanf("%s", qs);
		f = 0;
		flag = 0;
		for(int j = 0 ; qs[j] != '\0' ; j++){
			if(qs[j] == '1')
				f++;
			if(f > 1){
				flag = 1;
				break;	
			}
			if(qs[j] != '1' && qs[j] != '0'){
				flag = 1;
				break;
			}
		}
		if(flag == 1){
			for(int j = 0 ; qs[j] != '\0' ; j++){
				ss[j] = qs[j];
				// cout << "ww:" << ss[j] << endl;
				m++;
			}
		}
		else{
			if(qs[0] == '0'){
				flagger = 1;
			}
			for(int j = 1 ; qs[j] != '\0' ; j++){
				s[k++] = qs[j];
			}

		}
	}
	// cout << k << " " << m << endl;
	// cout << ss[0] << endl;
	if(flagger == 1){
		printf("0");
		return 0;
	}
	if(m == 0){
		printf("1%s", s);
		return 0;
	}
	for(int i = 0 ; i < k ; i++){
		ss[m++] = s[i];
	}
	ss[m] = '\0';
	printf("%s", ss);
	return 0;
}