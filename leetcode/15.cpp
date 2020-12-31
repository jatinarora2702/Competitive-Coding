class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int s = -nums[i];
            int f = i+1;
            int l = nums.size() - 1;
            while(f < l) {
                int z = nums[f] + nums[l];
                if (z == s) {
                    vector<int> entry;
                    entry.push_back(nums[i]);
                    entry.push_back(nums[f]);
                    entry.push_back(nums[l]);
                    ans.push_back(entry);
                    int t = f;
                    while(f < nums.size() && nums[t] == nums[f]) f++;
                    t = l;
                    while(l >= 0 && nums[t] == nums[l]) l--;
                }
                else if (z < s) {
                    f++;
                }
                else {
                    l--;
                }
            }
        }
        return ans;
    }
};