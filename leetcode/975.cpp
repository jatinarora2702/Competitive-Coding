class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n = A.size();
        if (n == 0) {
            return 0;
        }
        bool dp[n][2];
        int cnt = 1;
        dp[n-1][0] = dp[n-1][1] = true;
        set<pair<int, int>> st;
        st.insert(make_pair(A[n-1], n-1));
        for(int i = n-2; i >= 0; i--) {
            set<pair<int, int>>::iterator it1 = lower_bound(st.begin(), st.end(), make_pair(A[i], i));
            pair<int, int> p;
            if (it1 == st.begin()) {
                p = *it1;
                if (p.first == A[i]) {
                    dp[i][0] = dp[p.second][1];
                }
                else {
                    dp[i][0] = false;   
                }
            }
            else if (it1 == st.end()) {
                it1--;
                p = *it1;
                it1 = lower_bound(st.begin(), st.end(), make_pair(p.first, i));
                p = *it1;
                dp[i][0] = dp[p.second][1];
            }
            else {
                p = *it1;
                if (p.first == A[i]) {
                    dp[i][0] = dp[p.second][1];
                }
                else {
                    it1--;
                    p = *it1;
                    it1 = lower_bound(st.begin(), st.end(), make_pair(p.first, i));
                    p = *it1;
                    dp[i][0] = dp[p.second][1];   
                }
            }
            // cout << "p0.FF:" << p.first << " p0.SS:" << p.second << "\n"; 
            set<pair<int, int>>::iterator it2 = lower_bound(st.begin(), st.end(), make_pair(A[i], i));
            if (it2 == st.end()) {
                dp[i][1] = false;
            }
            else {
                p = *it2;
                dp[i][1] = dp[p.second][0];
            }
            // cout << "p1.FF:" << p.first << " p1.SS:" << p.second << "\n"; 
            // cout << "i=" << i << " 0:" << dp[i][0] << ", 1:" << dp[i][1] << "\n";
            if (dp[i][1]) {
                cnt++;
            }
            st.insert(make_pair(A[i], i));
        }
        return cnt;
    }
};