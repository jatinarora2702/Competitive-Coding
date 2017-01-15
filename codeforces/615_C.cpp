#include <bits/stdc++.h>
#define N 2200
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
using namespace std;
char s[N], t[N];
int a[30], pos[N];
map < int, string > mp;
vector < pair < int, int > > v;
int main(){
	int n, m, x, f, cnt, j;
	string str;
	scanf("%s %s", s, t);
	for(n = 0 ; s[n] != '\0' ; n++);
	for(m = 0 ; t[m] != '\0' ; m++);
	for(int i = 0 ; i < n ; i++){
		if(a[s[i]] == 0){
			a[s[i]] = 1;
			pos[s[i]] = i;
			str.assign(s+i);
			mp[(int)(s[i]-'a')] = str;
		}
	}
	cout << "pos:";
	for(int i = 0 ; i < 26 ; i++)
		cout << pos[i] << " ";
	cout << endl;
	cnt = 1;
	f = 0;
	j = 0;
	str = mp[t[0]-'a'];
	x = pos[t[0]-'a'];
	if(str.length() > 0){
		j++;
		f = 1;
		for(int i = 1 ; i < m ; i++){
			if(j >= str.length()){
				cnt++;
				v.PB(MP(x+1, x+j));
				str = mp[(int)(t[i]-'a')];
				j = 1;
				if(str.length() == 0){
					f = 0;
					break;
				}
				x = pos[t[i]-'a'];
			}
			else if(str[j] != t[i]){
				cnt++;
				v.PB(MP(x+1, x+j));
				j = 1;
				str = mp[(int)(t[i]-'a')];
				if(str.length() == 0){
					f = 0;
					break;
				}
				x = pos[t[i]-'a'];
			}
			else{
				j++;
			}
		}
	}
	if(f == 0)
		printf("-1");
	else{
		printf("%d", cnt);
		for(int i = 0 ; i < v.size() ; i++){
			printf("%d %d\n", v[i].FF, v[i].SS);
		}
	}
	return 0;
}