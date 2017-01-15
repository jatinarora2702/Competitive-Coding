#include <bits/stdc++.h>
using namespace std;
void find_lcs(char *s1, int i ,char *s2, int j, char *s, int &k, int len) {
	if(i < 0 or j < 0)
		return;
	if(s1[i] == s2[j]) {
		s[k] = s1[i];
		k = k+1;
		find_lcs(s1,i-1,s2,j-1,s,k,len);
	}
	else {
		char *ts1, *ts2;
		int k1, k2; 
		ts1 = new char[len + 1];
		ts2 = new char[len + 1];
		for(int i1 = 0 ; i1 < k + 1 ; i1++ ) {
			ts1[i1] = s[i1];
			ts2[i1] = s[i1];
		}
		k1 = k2 = k;
		find_lcs(s1,i,s2,j-1,ts1,k1,len);
		find_lcs(s1,i-1,s2,j,ts2,k2,len);
		if(k1 > k2) {
			k = k1;
			for(int i1 = 0 ; i1 < k1 ; i1++ ) {
				s[i1] = ts1[i1];
			}
		}
		else {
			k = k2;
			for(int i1 = 0 ; i1 < k2 ; i1++ ) {
				s[i1] = ts2[i1];
			}
		}
	}
}
int main() {
	char *s1,*s2, *s;
	int *dp, m, n, max, l, k;
	printf("Enter the length of 1st seq. : ");
	scanf("%d", &m);
	printf("Enter the seq. :\n");
	s1 = new char[m + 1];
	scanf("%s", s1);
	printf("Enter the length of 2nd seq. : ");
	scanf("%d", &n);
	printf("Enter the seq. :\n");
	s2 = new char[n + 1];
	scanf("%s", s2);
	l = (m < n) ? m : n;
	dp = new int[l];
	s = new char[l + 1];
	max = 0;
	k = 0;
	find_lcs(s1,m-1,s2,n-1,s,k,l);
	int i = 0;
	int j = k-1;
	char temp;
	while(i < j) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
	s[k] = '\0';
	printf("\nLCS has length : %d",k);
	printf("\nLCS is :\n");
	printf("%s\n",s);
	return 0;
}