class Solution {
public:
    int maxArea(vector<int>& height) {
        int n, a, f[2];
        n = height.size();
        a = 0;
        f[0] = 0;
        f[1] = n-1;
        while(f[0] < f[1]) {
            int m = height[f[0]] < height[f[1]] ? 0 : 1;
            a = max(a, height[f[m]] * (f[1] - f[0]));
            if (m == 0) {
                f[m]++;
            }
            else {
                f[m]--;
            }
        }
        return a;
    }
};