
#include <iostream>
#include <stdio.h>
using namespace std;
	int min_fn(int a, int b, int c){
	if(a < b){
		if(a < c)
			return a;
		else
			return c;
	}
	else{
		if(b < c)
			return b;
		else
			return c;
	}
}
int main() {
	int n, *dp, i, i2, i3, i5, v;
	printf("Enter the no. of the term of the ugly no.s series : ");
	scanf("%d", &n);
	dp = new int[n];
	dp[0] = 1;
	i2 = i3 = i5 = 0;
	for(int i = 1 ; i < n ; i++){
		v = min_fn(dp[i2]*2, dp[i3]*3, dp[i5]*5);
		if(v == dp[i2]*2){
			dp[i] = dp[i2]*2;
			i2++;
		}
		if(v == dp[i3]*3){
			dp[i] = dp[i3]*3;
			i3++;
		}
		if(v == dp[i5]*5){
			dp[i] = dp[i5]*5;
			i5++;
		}
	}
	printf("%dth term is : %d\n", n, dp[n-1]);
	for(int i =0 ; i < n ; i++)
		cout << dp[i] << endl;
	return 0;
}
/*

// CODE GIVEN ON GEEKS FOR GEEKS

# include<stdio.h>
# include<stdlib.h>
# define bool int
 
/* Function to find minimum of 3 numbers /
unsigned min(unsigned , unsigned , unsigned );
 
/* Function to get the nth ugly number/
unsigned getNthUglyNo(unsigned n)
{
    unsigned *ugly =
             (unsigned *)(malloc (sizeof(unsigned)*n));
    unsigned i2 = 0, i3 = 0, i5 = 0;
    unsigned i;
    unsigned next_multiple_of_2 = 2;
    unsigned next_multiple_of_3 = 3;
    unsigned next_multiple_of_5 = 5;
    unsigned next_ugly_no = 1;
    *(ugly+0) = 1;
 
    for(i=1; i<n; i++)
    {
       next_ugly_no = min(next_multiple_of_2,
                           next_multiple_of_3,
                           next_multiple_of_5);
       *(ugly+i) = next_ugly_no;                    
       if(next_ugly_no == next_multiple_of_2)
       {
           i2 = i2+1;       
           next_multiple_of_2 = *(ugly+i2)*2;
       }
       if(next_ugly_no == next_multiple_of_3)
       {
           i3 = i3+1;
           next_multiple_of_3 = *(ugly+i3)*3;
       }
       if(next_ugly_no == next_multiple_of_5)
       {
           i5 = i5+1;
           next_multiple_of_5 = *(ugly+i5)*5;
       }
    } /*End of for loop (i=1; i<n; i++) /
    return next_ugly_no;
}
 
/* Function to find minimum of 3 numbers /
unsigned min(unsigned a, unsigned b, unsigned c)
{
    if(a <= b)
    {
      if(a <= c)
        return a;
      else
        return c;
    }
    if(b <= c)
      return b;
    else
      return c;
}
 
/* Driver program to test above functions /
int main()
{
    unsigned no = getNthUglyNo(150);
    printf("%dth ugly no. is %d ", 150, no);
    getchar();
    return 0;
}

*/