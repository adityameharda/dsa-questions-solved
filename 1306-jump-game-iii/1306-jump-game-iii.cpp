class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int>vis(n,0);
        queue<int>q;
        q.push(start);
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            if(curr < 0 || curr >= n || vis[curr] == 1)
            {
                continue;
            }
            if(arr[curr] == 0)
            {
                return true;
            }
            vis[curr] = 1;
            int t1 = curr - arr[curr];
            int t2 = curr + arr[curr];
            q.push(t1);
            q.push(t2);
        }

        return false;

    }
};