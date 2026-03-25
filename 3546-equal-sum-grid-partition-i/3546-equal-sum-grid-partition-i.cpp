class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long total = 0;
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                total += grid[i][j];
            }
        }
        long long temp = 0;
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                temp += grid[i][j];
            }   
            if(2*temp == total) return true;
        }
        temp=0;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                temp += grid[j][i];
            }   
            if(2*temp == total) return true;
        }
        return false;

    }
};