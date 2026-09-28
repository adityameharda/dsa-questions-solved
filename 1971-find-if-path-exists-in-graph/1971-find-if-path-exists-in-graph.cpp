class Solution {
public:
    bool solve(int src,int dest, vector<int>&visited,vector<vector<int>>&adj){
        queue<int>q;
        q.push(src);  
        while(!q.empty()){
            int front = q.front();
            q.pop();
            if(front == dest)return true;
            visited[front] = 1;
            for(auto neigh : adj[front]){
                if(!visited[neigh]){
                    visited[neigh] = 1;
                    q.push(neigh);
                }
            }
        }
        return false;

        
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        vector<int>visited(n,0);
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return solve(source,destination,visited,adj);


    }
};