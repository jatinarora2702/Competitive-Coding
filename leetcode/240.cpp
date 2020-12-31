class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int e;
        e = matrix[0].size();
        for(int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] > target) {
                break;
            }
            if (matrix[i][e-1] < target) {
                continue;
            }
            int k = lower_bound(matrix[i].begin(), matrix[i].begin() + e, target) - matrix[i].begin();
            if (k < e && matrix[i][k] == target) {
                return true;
            }
            e = k + 1;
        }
        return false;
    }
};