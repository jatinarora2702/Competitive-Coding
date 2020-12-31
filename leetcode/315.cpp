class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        return getAns(nums, 0, n-1);
    }
    
    vector<int> getAns(vector<int>& nums, int s, int e) {
        vector<int> ans;
        if (s > e) {
            return ans;
        }
        if (s == e) {
            ans.push_back(0);
            return ans;
        }
        int m = (s + e) / 2;
        vector<int> lans = getAns(nums, s, m);
        vector<int> rans = getAns(nums, m+1, e);
        vector<int> temp;
        for(int i = m+1; i <= e; i++) {
            temp.push_back(nums[i]);
        }
        sort(temp.begin(), temp.end());
        for(int i = s; i <= m; i++) {
            lans[i-s] += (int)(lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin());
        }
        for(int i = m+1; i <= e; i++) {
            lans.push_back(rans[i-m-1]);
        }
        return lans;
    }
};