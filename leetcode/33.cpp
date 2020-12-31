class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s, l, k, n;
        n = nums.size();
        if (n == 0) {
            return -1;
        }
        s = 0;
        l = n - 1;
        k = -1;
        while(s <= l) {
            int m = (s + l) / 2;
            if (nums[s] <= nums[m] && nums[m] <= nums[l]) {
                k = s;
                break;
            }
            if (nums[m] > nums[l]) {
                s = m+1;
            }
            else if (nums[m] < nums[s]) {
                l = m;
            }
        }
        k = s;
        s = 0;
        l = n - 1;
        while(s <= l) {
            int m = (s + l) / 2;
            if (nums[(m+k)%n] == target) {
                return (m+k)%n;
            }
            if (nums[(m+k)%n] < target) {
                s = m+1;
            }
            else {
                l = m-1;
            }
        }
        return -1;
    }
};