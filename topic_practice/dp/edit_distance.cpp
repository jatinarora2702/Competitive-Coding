#include <bits/stdc++.h>
using namespace std;
int min(int a, int b, int c) {
	if(a < b) {
		if(a < c)
			return a;
		else
			return c;
	}
	else {
		if(b < c) 
			return b;
		else
			return c;
	}
}
int main() {
	int **dp, m, n, in, d, r, min1, min2, min3;
	string a,b;
	cout << "Enter the string to change :\n";
	cin >> a;
	cout << "Enter the string to be made :\n";
	cin >> b;
	m = a.size();
	n = b.size();
	cout << "Enter the cost of replacement : ";
	cin >> r;
	cout << "\nEnter the cost of insertion : ";
	cin >> in;
	cout << "\nEnter the cost of deletion : ";
	cin >> d;
	dp = new int*[m+1];
	for(int i = 0 ; i <= m ; i++ ) {
		dp[i] = new int[n+1];
	}
	dp[0][0] = 0;
	for(int i = 0 ; i <= m ; i++ ) {
		dp[i][0] = i*d;
	}
	for(int j = 0 ; j <= n ; j++ ) {
		dp[0][j] = j*in;
	}
	for(int i = 1 ; i <= m ; i++ ) {
		for(int j = 1 ; j <= n ; j++ ) {
			min1 = (a[i] == b[j]) ? 0 : r;
			min1 += dp[i-1][j-1];
			dp[i][j] = min(min1, dp[i-1][j] + d, dp[i][j-1] + in);
		}
	}
	cout << "The minimum edit distance is : " << dp[m][n] << endl;
	return 0;
}
/*

// CODE FROM INTERNET
// ------------------

// Dynamic Programming implementation of edit distance
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
// Change these strings to test the program
#define STRING_X "SUNDAY"
#define STRING_Y "SATURDAY"
 
#define SENTINEL (-1)
#define EDIT_COST (1)
 
inline
int min(int a, int b) {
   return a < b ? a : b;
}
 
// Returns Minimum among a, b, c
int Minimum(int a, int b, int c)
{
    return min(min(a, b), c);
}
 
// Strings of size m and n are passed.
// Construct the Table for X[0...m, m+1], Y[0...n, n+1]
int EditDistanceDP(char X[], char Y[])
{
    // Cost of alignment
    int cost = 0;
    int leftCell, topCell, cornerCell;
 
    int m = strlen(X)+1;
    int n = strlen(Y)+1;
 
    // T[m][n]
    int *T = (int *)malloc(m * n * sizeof(int));
 
    // Initialize table
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            *(T + i * n + j) = SENTINEL;
 
    // Set up base cases
    // T[i][0] = i
    for(int i = 0; i < m; i++)
        *(T + i * n) = i;
 
    // T[0][j] = j
    for(int j = 0; j < n; j++)
        *(T + j) = j;
 
    // Build the T in top-down fashion
    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            // T[i][j-1]
            leftCell = *(T + i*n + j-1);
            leftCell += EDIT_COST; // deletion
 
            // T[i-1][j]
            topCell = *(T + (i-1)*n + j);
            topCell += EDIT_COST; // insertion
 
            // Top-left (corner) cell
            // T[i-1][j-1]
            cornerCell = *(T + (i-1)*n + (j-1) );
 
            // edit[(i-1), (j-1)] = 0 if X[i] == Y[j], 1 otherwise
            cornerCell += (X[i-1] != Y[j-1]); // may be replace
 
            // Minimum cost of current cell
            // Fill in the next cell T[i][j]
            *(T + (i)*n + (j)) = Minimum(leftCell, topCell, cornerCell);
        }
    }
 
    // Cost is in the cell T[m][n]
    cost = *(T + m*n - 1);
    free(T);
    return cost;
}
 
// Recursive implementation
int EditDistanceRecursion( char *X, char *Y, int m, int n )
{
    // Base cases
    if( m == 0 && n == 0 )
        return 0;
 
    if( m == 0 )
        return n;
 
    if( n == 0 )
        return m;
 
    // Recurse
    int left = EditDistanceRecursion(X, Y, m-1, n) + 1;
    int right = EditDistanceRecursion(X, Y, m, n-1) + 1;
    int corner = EditDistanceRecursion(X, Y, m-1, n-1) + (X[m-1] != Y[n-1]);
 
    return Minimum(left, right, corner);
}
 
int main()
{
    char X[] = STRING_X; // vertical
    char Y[] = STRING_Y; // horizontal
 
    printf("Minimum edits required to convert %s into %s is %d\n",
           X, Y, EditDistanceDP(X, Y) );
    printf("Minimum edits required to convert %s into %s is %d by recursion\n",
           X, Y, EditDistanceRecursion(X, Y, strlen(X), strlen(Y)));
 
    return 0;
}

// -------------------- END -----------------------
*/