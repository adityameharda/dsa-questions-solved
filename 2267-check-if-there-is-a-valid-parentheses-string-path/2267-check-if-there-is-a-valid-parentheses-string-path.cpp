class Solution {
public:
    bool solve(vector<vector<char>>& grid,int i , int j,int count,vector<vector<vector<int>>> &dp){
        int m = grid.size();
        int n = grid[0].size();

        if(i >= m || j >= n) return false;
        if(grid[i][j] == '(') count++;
        else count--;

        if(count < 0) return false;
        if(count > m+n) return false;

        if(i == m-1 && j == n-1) {
            if(count == 0)return true ;
        }

        if(dp[i][j][count] != -1) return dp[i][j][count];

        return dp[i][j][count] = solve(grid, i+1, j, count,dp) || solve(grid, i, j+1, count,dp);

    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if((m+n-1) % 2 != 0) return false;
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(m+n+1,-1)));
        if(grid[0][0] == ')' || grid[m-1][n-1] == '(') return false;
        return solve(grid,0,0,0,dp);
    }
};