#include <bits/stdc++.h>
#define lldd long long int
#define mp make_pair
#define pb push_back
using namespace std;
#define mod 1000000007
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x1,x2,y1,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		if(x1==x2)
		{
		if(y1>y2)
		printf("down\n");
		else
		printf("up\n");
		}
		else if(y1==y2)
		{
		if(x1>x2)
		printf("left\n");
		else
		printf("right\n");
		}
		else
		printf("sad\n");
	}
	return 0;
}