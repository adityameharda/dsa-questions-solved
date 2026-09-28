class Solution {
public:
    void solve(vector<vector<char>>& grid,vector<vector<int>>& visited,int i,int j){
        int n = grid.size();
        int m = grid[0].size();
    
        queue<pair<int,int>>q;
        q.push({i,j});

        vector<int>dx ={0,0,-1,1};
        vector<int>dy ={1,-1,0,0};

        visited[i][j] = 1;

        while(!q.empty()){

            auto[row,col]  = q.front();
            q.pop();

            for(int k = 0 ; k < 4 ; k++){
                int newrow = row + dx[k];
                int newcol = col + dy[k];
                if(newrow < n && newrow >= 0 && newcol >= 0 && newcol < m && grid[newrow][newcol] == '1' && visited[newrow][newcol] == 0){
                    q.push({newrow,newcol});
                    visited[newrow][newcol] = 1;
                }
            }
           
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '1' && visited[i][j] == 0){
                    count++;
                    solve(grid,visited,i,j);
                }
            }
        }
        return count ;

    }
};