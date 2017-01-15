#include <cstdio>
#define N 100000
char pat[N], text[N], concatt[N];
int z[N];
int main(){
	int i, j, cnt, n, l, r, k, m;
	printf("Enter the text :\n");
	scanf("%s", text);
	printf("Enter the pattern to find :\n");
	scanf("%s", pat);
	for(i = 0 ; pat[i] != '\0' ; i++)
		concatt[i] = pat[i];
	m = i;
	concatt[i++] = '$';
	for(j = 0 ; text[j] != '\0' ; j++)
		concatt[i++] = text[j];
	n = i;
	cnt = 0;
	l = -1;
	r = -1;
	printf("pattern found starting from :\n");
	for(i = 1 ; i < n ; i++){
		if(i <= r){
			k = i-l;
			if(z[k] <= r-i+1)
				z[i] = z[k];
			else{
				k = r-l+1;
				l = i;
				while(concatt[r+1] == concatt[k]){
					r++; k++;
				}
				if(r == k-1)
					z[i] = z[k];
				else
					z[i] = r-l+1;
			}
		}
		else{
			l = r = -1;
			k = 0;
			z[i] = 0;
			while(concatt[k] == concatt[i+r+1]){
				k++; r++;
			}
			if(r >= 0){
				l = i;
				z[i] = i+r-l+1;
			}
		}
		if(z[i] >= m)
			printf("char # %d\n", i-m);
	}
	// printf("%s\n", concatt);
	// for(i = 0 ; i < n ; i++)
	// 	printf("%d ", z[i]);
	// printf("\n");
	// for(i = 0 ; i < n ; i++)
	// 	if(z[i] >= m)
	// 		cnt++;
	// printf("pattern found in the text : %d times\n", cnt);
	return 0;
}