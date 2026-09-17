class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int left = 0 ;
        int len = 0;
        vector<int>arr(128,0);
        for(int right = 0 ; right < n ; right++){
            while(arr[s[right]] > 0){
                arr[s[left]]--;
                left++;
            }
            arr[s[right]]++;
            len = max(len,right-left+1);
        }
        return len;
    }
};