class Solution {
public:
    int bfs(vector<string>& classroom, int energy){
        int n = classroom.size();
        int m = classroom[0].size();

        int sr,sc;
        vector<vector<int>> litterId(n, vector<int>(m,-1));
        int litterCount = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if(classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount;
                    litterCount++;
                }
            }
        }

        if(litterCount == 0)
            return 0;

        int allMask = (1 << litterCount) - 1;

        queue<tuple<int,int,int,int>> q;

        q.push({sr,sc,energy,0});

        vector<vector<vector<vector<bool>>>> visited(
            n,
            vector<vector<vector<bool>>>(
                m,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litterCount,false)
                )
            )
        );

        visited[sr][sc][energy][0] = true;

        vector<int>dx = {1,-1,0,0};
        vector<int>dy = {0,0,-1,1};

        int count = 0;
        int maxenergy = energy;

        while(!q.empty())
        {
            int size = q.size();

            while(size--) {

                auto [row,col,currenergy,mask] = q.front();
                q.pop();

                if(mask == allMask)
                    return count;

                for(int i = 0; i < 4; i++){

                    int newrow = row + dx[i];
                    int newcol = col + dy[i];

                    if(newrow < 0 || newrow >= n ||
                       newcol < 0 || newcol >= m)
                        continue;

                    if(classroom[newrow][newcol] == 'X')
                        continue;

                    int newenergy = currenergy - 1;

                    if(newenergy < 0)
                        continue;


                    if(classroom[newrow][newcol] == 'R')
                        newenergy = maxenergy;

                
                    int newmask = mask;

                    if(classroom[newrow][newcol] == 'L'){

                        int id = litterId[newrow][newcol];

                        newmask = mask | (1 << id);
                    }

                    if(visited[newrow][newcol][newenergy][newmask])
                        continue;

                    visited[newrow][newcol][newenergy][newmask] = true;

                    q.push({newrow,newcol,newenergy,newmask});
                }
            }

            count++;
        }

        return -1;
    }

    int minMoves(vector<string>& classroom, int energy) {
        return bfs(classroom,energy);
    }
};