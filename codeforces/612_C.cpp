#include <bits/stdc++.h>
#define N 1000005
using namespace std;
stack < char > stk;
char s[N];
int main() {
	int cnt, f;
	char ch;
	cnt = 0;
	scanf("%s", s);
	f = 1;
	for(int i = 0 ; s[i] != '\0' ; i++){
		if(s[i] == '{' || s[i] == '(' || s[i] == '[' || s[i] == '<')
			stk.push(s[i]);
		else{
			if(stk.empty()){
				f = 0;
				break;
			}
			ch = stk.top();
			stk.pop();
			// cout << "ch:" << ch << endl;
			if(ch == '}' || ch == ']' || ch == ')' || ch == '>'){
				f = 0;
				break;
			}
			else if(!((ch == '{' && s[i] == '}') || (ch == '<' && s[i] == '>') || (ch == '[' && s[i] == ']') || (ch == '(' && s[i] == ')')))
				cnt++;
		}
	}
	if(!stk.empty())
		f = 0;
	if(f == 1)
		printf("%d", cnt);
	else
		printf("Impossible");
	return 0;
}