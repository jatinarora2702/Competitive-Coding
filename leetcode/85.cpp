class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) {
            return 0;
        }
        int m = matrix[0].size();
        if (m == 0) {
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(m));
        for(int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j] == '0' ? 0 : 1;
            for(int i = 1; i < n; i++) {
                dp[i][j] = matrix[i][j] == '0' ? 0 : (dp[i-1][j] + 1);
            }
        }
        int maxm = 0;
        for(int i = 0; i < n; i++) {
            stack<int> stk;
            vector<int> left(m);
            for(int j = 0; j < m; j++) {
                left[j] = j;
                int p = j;
                while(!(stk.size() == 0) && dp[i][stk.top()] >= dp[i][j]) {
                    left[j] = left[stk.top()];
                    p = stk.top();
                    stk.pop();
                }
                stk.push(p);
                if (p != j) {
                    stk.push(j);
                }
            }
            while(!(stk.size() == 0)) {
                stk.pop();
            }
            vector<int> right(m);
            for(int j = m-1; j >= 0; j--) {
                right[j] = j;
                int p = j;
                while(!(stk.size() == 0) && dp[i][stk.top()] >= dp[i][j]) {
                    right[j] = right[stk.top()];
                    p = stk.top();
                    stk.pop();
                }
                stk.push(p);
                if (p != j) {
                    stk.push(j);
                }
            }
            for(int j = 0; j < m; j++) {
                maxm = max(maxm, (right[j] - left[j] + 1) * dp[i][j]);
            }
        }
        return maxm;
    }
};