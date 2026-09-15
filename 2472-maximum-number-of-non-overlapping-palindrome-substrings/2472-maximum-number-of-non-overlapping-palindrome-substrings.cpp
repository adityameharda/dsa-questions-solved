class Solution {
public:
    // bool palin(string &s , int left , int right){
    //     if(left >= right) return true;
    //     if(s[left] != s[right])return false ;

    //     return  palin(s , left + 1 , right -1);
    // }
    int solve(string &s, int k,int idx,vector<int>&dp, vector<vector<bool>>&palin){
        int n = s.length();
        if(idx >= s.length())return 0;

        if(dp[idx] != -1) return dp[idx];

        int ans = solve(s,k,idx+1,dp,palin) ;
        // int curr = 0;
        for(int i = k+idx-1 ; i < s.length() ; i++){
            if(palin[idx][i]){
                ans = max(ans,1+solve(s,k,i+1,dp,palin));
            }
        }
        return dp[idx] =  ans;
    }
    int maxPalindromes(string s, int k) {
        int n = s.length();
        vector<vector<bool>> palin(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++) {
            palin[i][i] = true;
        }
        for(int i = 2; i <= n; i++) {
            for(int j = 0; j + i - 1 < n; j++) {
                int end = i+j -1;
                if(s[j] == s[end]){
                    if(i == 2)palin[j][end] = true;
                    else
                        palin[j][end] = palin[j+1][end-1];
                }
            }
        }
        vector<int>dp(n+1,-1);
        return solve(s,k,0,dp,palin);
    }
};