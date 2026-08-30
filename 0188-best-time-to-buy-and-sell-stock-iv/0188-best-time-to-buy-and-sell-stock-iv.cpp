class Solution {
public:
    int solve(int k, vector<int>& prices,int idx,int buy,vector<vector<vector<int>>>&dp){
        int n = prices.size();
        if(idx == n || k == 0) return 0;
        if(dp[idx][k][buy] != -1) return dp[idx][k][buy] ;
        if(buy){
            //take
            int take =-prices[idx] + solve(k,prices,idx+1,0,dp);
            // skip
            int skip = solve(k,prices,idx+1,1,dp);
            return dp[idx][k][buy] = max(skip,take);
        }else{
            //sell
            int sell = prices[idx]+solve(k-1,prices,idx+1,1,dp);
            //skip 
            int skip = solve(k,prices,idx+1,0,dp);
            return dp[idx][k][buy] = max(skip,sell);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(101,vector<int>(2,-1)));
        return solve(k,prices,0,1,dp);
    }
};