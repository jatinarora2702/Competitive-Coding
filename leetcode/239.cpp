class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int> > > q;
        for(int i = 0; i < k; i++) {
            q.push(make_pair(nums[i], i));
        }
        vector<int> ans;
        if (q.size() > 0) {
            ans.push_back(q.top().first);
        }
        for(int i = k; i < nums.size(); i++) {
            q.push(make_pair(nums[i], i));
            while(q.top().second <= i-k) {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};
