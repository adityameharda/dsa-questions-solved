class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            sort(grid[i].begin(), grid[i].end());
        }

        int res = 0;

        for (int j = 0; j < n; j++) {
            int maxi = 0;

            for (int i = 0; i < m; i++) {
                maxi = max(maxi, grid[i][j]);
            }

            res += maxi;
        }

        return res;
    }
};