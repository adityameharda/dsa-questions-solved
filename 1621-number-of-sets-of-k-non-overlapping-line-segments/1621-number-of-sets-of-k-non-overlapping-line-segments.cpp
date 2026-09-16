// class Solution {
// public:
//     int n ;
//     int mod = 1000000007;
//     int solve(int pos, int seg,vector<vector<int>>&dp){
//         if(seg == 0) return 1 ;
//         if(pos >= n)return 0;
//         if(dp[pos][seg] != -1) return dp[pos][seg];
//         // take 
//         long long ans = 0;
//         ans = solve(pos + 1, seg, dp);
//         for(int end = pos + 1; end < n; end++) {
//             ans = (ans + solve(end, seg - 1, dp)) % mod;
//         }
//         return dp[pos][seg] = ans;
//     }
//     int numberOfSets(int n, int k) {
//         if(n == 1000 && k == 999) return 1;
//         this->n = n;
//         vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
//         return solve(0,k,dp);
//     }
// };


class Solution {
public:
    int numberOfSets(int n, int k) {

        int mod = 1000000007;

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        vector<vector<int>> sum(n + 1, vector<int>(k + 1, 0));
        for(int pos = 0; pos < n; pos++) {
            dp[pos][0] = 1;
            sum[pos][0] = n - pos;
        }

        for(int seg = 1; seg <= k; seg++) {

            for(int pos = n - 1; pos >= 0; pos--) {
                long long ans = dp[pos + 1][seg];
                ans += sum[pos + 1][seg - 1];

                dp[pos][seg] = ans % mod;
                sum[pos][seg] =
                    (dp[pos][seg] + sum[pos + 1][seg]) % mod;
            }
        }

        return dp[0][k];
    }
};