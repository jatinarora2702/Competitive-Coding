class Solution {
public:
    // works.. but the time constraints are very strict for this problem.. so, more optimization in handling is required.. this gives TLE..
    int numSquarefulPerms(vector<int>& A) {
        vector<int> v;
        return dfs(A, v, 0);
    }
    
    int dfs(vector<int>& v, vector<int>& res, int si) {
        if (si == v.size()) {
            return check(res) ? 1 : 0;
        } 
        else {
            int cnt = 0;
            unordered_set<int> st;
            for(int i = si; i < v.size(); i++) {
                if (st.find(v[i]) == st.end()) {
                    st.insert(v[i]);
                    res.push_back(v[i]);
                    int t = v[si];
                    v[si] = v[i];
                    v[i] = t;
                    cnt += dfs(v, res, si+1);
                    t = v[si];
                    v[si] = v[i];
                    v[i] = t;
                    res.pop_back();
                }
            }
            return cnt;
        }
    }
    
    bool check(vector<int>& v) {
        for(int i = 0; i < v.size()-1; i++) {
            int n = v[i] + v[i+1];
            int s = sqrt(n);
            if (s * s != n) {
                return false;
            }
        }
        return true;
    }
};