#include <bits/stdc++.h>
#include <set>
using namespace std;
class stud{
public:
	int *a, n;
	stud(int *b, int m) : n(m){
		a = new int[n];
		for(int i = 0 ; i < n ; i++)
			a[i] = b[i];
	}
};
class cmp{
	stud s1;
	int operator () (stud s2){
		int n = s1.n;
		for(int i = 0 ; i < n ; i++){
			if(s1.a[i] < s2.a[i])
				return true;
			else if(s1.a[i] > s2.a[i])
				return false;
		}
		return false;	
	}
};

int main(){
	int *a, n, f;
	set < stud, cmp > s;
	set < stud, cmp > :: iterator it;
	while(true){
		cout << "enter choice : ";
		cin >> f;
		if(f == 0)
			break;
		else{
			cout << "enter n : ";
			cin >> n;
			for(int i = 0 ; i < n ; i++)
				scanf("%d", &a[i]);
			stud s1(a, n);
			it = s.find(s1);
			if(it != s.end()){
				printf("NOT FOUND..inserting..\n");
				s.insert(s1);
			}
			else{
				printf("SET ALREADY PRESENT.. skipping..\n");
			}
		}
	}
	return 0;
}