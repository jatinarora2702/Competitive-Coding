class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int l, maxm;
        l = 0;
        maxm = 0;
        for(int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            }
            else {
                if (stk.size() > 1) {
                    stk.pop();
                    maxm = max(maxm, i-stk.top());
                }
                else if (stk.size() == 1) {
                    stk.pop();
                    maxm = max(maxm, i-l+1);
                }
                else {
                    l = i+1;
                }
            }
        }
        return maxm;
    }
};