class Solution {
public:
    int maxJumps(vector<int>& arr, int d) 
    {
        int n = arr.size();
        vector<int> dp(n, 1);
        queue<int> q;
        for (int i = 0; i < n; i++) 
        {
            q.push(i);
        }
        while (!q.empty()) 
        {
            int i = q.front();
            q.pop();
            for (int j = i + 1; j <= min(n - 1, i + d); j++) 
            {

                if (arr[j] >= arr[i])
                    break;

                if (dp[j] < dp[i] + 1) 
                {
                    dp[j] = dp[i] + 1;
                    q.push(j);
                }
            }
            for (int j = i - 1; j >= max(0, i - d); j--) 
            {
                if (arr[j] >= arr[i])
                    break;
                if (dp[j] < dp[i] + 1) {
                    dp[j] = dp[i] + 1;
                    q.push(j);
                }
            }
        }
        int ans = 1;
        for (int x : dp) 
        {
            ans = max(ans, x);
        }
        return ans;
    }
};