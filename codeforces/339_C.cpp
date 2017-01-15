#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int main() {
	int m, s1, s2, f, fold;
	char s[11];
	vector < int > v;
	scanf("%s%d", s, &m);
	s1 = s2 = 0;
	f = fold = 0;
	for(int i = 0 ; i < m ; i++){
		fold = f;
		for(int j = 0 ; j < 10 ; j++){
			if(f == 0 and s[j] == '1' and s1+j+1 > s2){
				if(v.size() != 0 and v.back() == (j+1))
					continue;
				s1 += (j+1);
				v.push_back(j+1);
				f ^= 1;
				break;
			}
			else if(f == 1 and s[j] == '1' and v.back() != (j+1) and s2+j+1 > s1){
				s2 += (j+1);
				v.push_back(j+1);
				f ^= 1;
				break;
			}
		}
		if(fold == f)
			break;
	}
	if(fold == f)
		printf("NO");
	else{
		printf("YES\n");
		for(int i = 0 ; i < v.size() ; i++){
			printf("%d ", v[i]);
		}
	}
	return 0;
}