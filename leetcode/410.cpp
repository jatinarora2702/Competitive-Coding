class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        long long dp[n][m];
        dp[0][0] = nums[0];
        for(int i = 1; i < n; i++) {
            dp[i][0] = dp[i-1][0] + nums[i];
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < min(m, i+1); j++) {
                long long s = 0;
                long long minm = 0;
                for(int k = 1; i-k >= j-1 && j >= 1; k++) {
                    if (s == 0) {
                        s += nums[i-k+1];
                        minm = max(dp[i-k][j-1], s);
                    }
                    else {
                        s += nums[i-k+1];
                        minm = min(minm, max(dp[i-k][j-1], s));
                    }
                }
                dp[i][j] = minm;
            }
        }
        return dp[n-1][m-1];
    }
};