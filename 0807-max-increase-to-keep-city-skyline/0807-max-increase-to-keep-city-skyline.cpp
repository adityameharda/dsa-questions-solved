class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> rowmax(n);
        vector<int> colmax(m);
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                rowmax[i] = max(rowmax[i], grid[i][j]);
            }
        }
        for(int j = 0 ; j < n ; j++)
        {
            for(int i = 0 ; i < m ; i++)
            {
                colmax[j] = max(colmax[j], grid[i][j]);
            }
        }
        int ans = 0 ; 
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
               int mini =  min(rowmax[i],colmax[j]);
                ans += (mini - grid[i][j]);
            }
        }
        return ans;
    }
};