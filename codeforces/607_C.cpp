#include <bits/stdc++.h>
#define N 1000005
using namespace std;
string ss1, ss2;
char s1[N], s2[N], s3[N], s4[N], s5[N];
int main(){
	int n, f, j;
	scanf("%d%s %s", &n, s1, s2);
	// cout << s1 << " " << s2 << endl;
	j = 0;
	for(int i = n-2 ; i >= 0 ; i--){
		if(s1[i] == 'E')
			s3[j] = 'W';
		else if(s1[i] == 'W')
			s3[j] = 'E';
		else if(s1[i] == 'N')
			s3[j] = 'S';
		else if(s1[i] == 'S')
			s3[j] = 'N';
		j++;
	}
	s3[j] = '\0';
	// cout << "s3:" << s3 << endl;
	j = n-2;
	f = 1;
	for(int i = 0 ; i < n-1 ; i++){
		s4[i] = s3[i];
		s4[i+1] = '\0';
		// cout << s4 << endl;
		ss1.assign(s4);
		s5[i] = s2[j];
		s5[i+1] = '\0';
		ss2.assign(s5);
		// cout << ss2 << endl;
		reverse(ss2.begin(), ss2.end());
		if(ss1.compare(ss2) == 0){
			f = 0;
			break;
		}
		j--;
	}
	if(f == 0)
		printf("NO");
	else
		printf("YES");
	return 0;
}