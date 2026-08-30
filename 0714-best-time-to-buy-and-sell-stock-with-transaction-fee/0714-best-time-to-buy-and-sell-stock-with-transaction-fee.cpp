class Solution {
public:
    int solve(vector<int>& prices, int fee,int idx,int buy,vector<vector<int>>&dp){
        int n = prices.size();
        // if(fee==0) return 0;
        if(idx == n)return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy] ;
        if(buy){
            //take 
            int take = -prices[idx] + solve(prices,fee,idx+1,0,dp);
            // skip
            int skip = solve(prices,fee,idx+1,1,dp);
            return dp[idx][buy] = max(take,skip);
        }else{
            //sell
            int sell = prices[idx] - fee +solve(prices,fee,idx+1,1,dp);
            // skip
            int skip = solve(prices,fee,idx+1,0,dp);
            return dp[idx][buy] = max(sell,skip);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(prices,fee,0,1,dp);
    }
};