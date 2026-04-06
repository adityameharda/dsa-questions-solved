class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string ans = "";
        for (int i = 0; i < n; i++) 
        {
            int start = i, end = i;
            while (start >= 0 && end < n && s[start] == s[end]) 
            {
                if (end - start + 1 > ans.length()) 
                {
                    ans = s.substr(start, end - start + 1);
                }
                start--;
                end++;
            }
            start = i;
            end = i + 1;
            while (start >= 0 && end < n && s[start] == s[end]) 
            {
                if (end - start + 1 > ans.length()) 
                {
                    ans = s.substr(start, end - start + 1);
                }
                start--;
                end++;
            }
        }
        return ans;
    }
};


