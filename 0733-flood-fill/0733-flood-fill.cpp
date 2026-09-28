class Solution {
public:
    void solve(int sr,int sc,vector<vector<int>>& image,int color){
        int m =image.size();
        int n = image[0].size();
        int oc = image[sr][sc];
        if(oc == color)return;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc] = color;
        vector<int>dx = {1,-1,0,0};
        vector<int>dy = {0,0,-1,1};
        while(!q.empty()){

            auto [row , col] = q.front();
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int newrow = row + dx[i];
                int newcol = col + dy[i];
                if(newrow >=0 && newrow < m && newcol >= 0 && newcol < n  && image[newrow][newcol] == oc){
                    image[newrow][newcol] = color;
                    q.push({newrow,newcol});
                }
            }

        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       
        solve(sr,sc,image,color);
        return image;
    }
};