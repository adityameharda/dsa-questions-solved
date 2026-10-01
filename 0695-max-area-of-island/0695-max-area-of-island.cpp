class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j,vector<vector<int>>visited){
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<int>dx = {-1,1,0,0};
        vector<int>dy = {0,0,-1,1};
        queue<pair<int,int>>q;
        q.push({i,j});
        visited[i][j] = 1;

        while(!q.empty()){
            auto[row,col] = q.front();
            q.pop();
            count++;
            for(int k = 0 ; k < 4 ; k++){
                int nr = row + dx[k];
                int nc = col + dy[k];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1 && !visited[nr][nc])
                {
                    visited[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
        return count;


    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int ans = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(visited[i][j] == 0 && grid[i][j] == 1)
                ans = max(ans,solve(grid,i,j,visited));
            }
        }
        return ans;
    }
};