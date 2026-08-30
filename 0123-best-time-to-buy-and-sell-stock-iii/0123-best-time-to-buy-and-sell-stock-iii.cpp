class Solution {
public:
    int solve(vector<int>& prices,int idx,int buy,int limit,vector<vector<vector<int>>>&dp){
        int n = prices.size();
        if(idx == n || limit == 2)return 0;
        if(dp[idx][buy][limit] != -1) return dp[idx][buy][limit];
        if(buy){
            //take
            int take = -prices[idx] + solve(prices,idx+1,0,limit,dp);
            int skip = solve(prices,idx+1,1,limit,dp);
            return dp[idx][buy][limit] = max(take,skip);
        }else{
            int sell = prices[idx] + solve(prices,idx+1,1,limit+1,dp);
            int skip = solve(prices,idx+1,0,limit,dp);
            return dp[idx][buy][limit] =  max(skip,sell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(2,-1)));
        return solve(prices,0,1,0,dp);
    }
};