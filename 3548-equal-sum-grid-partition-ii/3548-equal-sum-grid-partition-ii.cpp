class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long sum = 0 ;

        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                sum += grid[i][j];
            }
        }
        unordered_map<long long,int> top, bottom, left, right;
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                bottom[grid[i][j]]++;
                right[grid[i][j]]++;
            }
        }
        long long temp = 0 ;
        for(int i = 0 ; i < m-1 ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                temp += grid[i][j];
                top[grid[i][j]]++;
                bottom[grid[i][j]]--;

                if(bottom[grid[i][j]] == 0)
                {
                    bottom.erase(grid[i][j]);
                }
            }
            long long other = sum - temp;
            if(temp == other) return true;
            if(temp > other)
            {
                long long diff = temp - other;

                if(top.count(diff))
                {
                    int h = i + 1;
                    int w = n;

                    if(h > 1 && w > 1) return true;

                    if(h == 1)
                    {
                        if(grid[0][0] == diff || grid[0][n-1] == diff) return true;
                    }
                    else
                    {
                        if(grid[0][0] == diff || grid[i][0] == diff) return true;
                    }
                }
            }
            else
            {
                long long diff = other - temp;

                if(bottom.count(diff))
                {
                    int h = m - i - 1;
                    int w = n;

                    if(h > 1 && w > 1) return true;

                    if(h == 1)
                    {
                        if(grid[i+1][0] == diff || grid[i+1][n-1] == diff) return true;
                    }
                    else
                    {
                        if(grid[i+1][0] == diff || grid[m-1][0] == diff) return true;
                    }
                }
            }
        }

        temp = 0 ;
        for(int i = 0 ; i < n-1 ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                temp += grid[j][i];
                left[grid[j][i]]++;
                right[grid[j][i]]--;

                if(right[grid[j][i]] == 0)
                {
                    right.erase(grid[j][i]);
                }
            }
            long long other = sum - temp;
            if(temp == other) return true;
            if(temp > other)
            {
                long long diff = temp - other;

                if(left.count(diff))
                {
                    int h = m;
                    int w = i + 1;

                    if(h > 1 && w > 1) return true;

                    if(h == 1)
                    {
                        if(grid[0][0] == diff || grid[0][i] == diff) return true;
                    }
                    else
                    {
                        if(grid[0][0] == diff || grid[m-1][0] == diff) return true;
                    }
                }
            }
            else
            {
                long long diff = other - temp;

                if(right.count(diff))
                {
                    int h = m;
                    int w = n - i - 1;

                    if(h > 1 && w > 1) return true;

                    if(h == 1)
                    {
                        if(grid[0][i+1] == diff || grid[0][n-1] == diff) return true;
                    }
                    else
                    {
                        if(grid[0][i+1] == diff || grid[m-1][i+1] == diff) return true;
                    }
                }
            }
        }

        return false ;
    }
};