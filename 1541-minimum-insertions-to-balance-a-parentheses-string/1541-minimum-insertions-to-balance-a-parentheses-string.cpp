class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                open++;
            } else {
                if (open == 0) {
                    open++;
                    ans++;
                }
                if (i + 1 < s.length() && s[i + 1] == ')') {
                    i++;
                } else {
                    ans++;
                }
                open--;
            }
        }
        return ans + 2 * open;
    }
};