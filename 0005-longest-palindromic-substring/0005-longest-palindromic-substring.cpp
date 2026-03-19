// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int count = 0 ;
//         int start = 0 ;
//         int end  = s.length()-1;
//         string ans = "";
//         while(start <= end)
//         {
//             if(s[start] == s[end]){
//                 ans.push_back(s[start]);
//                 start++;
//                 end--;
//             }else ans = "";
//             start++;
//             end--;
//         }
//         return ans;
//     }
// };


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string ans = "";

        for (int i = 0; i < n; i++) {
            // odd length palindrome
            int start = i, end = i;
            while (start >= 0 && end < n && s[start] == s[end]) {
                if (end - start + 1 > ans.length()) {
                    ans = s.substr(start, end - start + 1);
                }
                start--;
                end++;
            }

            // even length palindrome
            start = i;
            end = i + 1;
            while (start >= 0 && end < n && s[start] == s[end]) {
                if (end - start + 1 > ans.length()) {
                    ans = s.substr(start, end - start + 1);
                }
                start--;
                end++;
            }
        }

        return ans;
    }
};