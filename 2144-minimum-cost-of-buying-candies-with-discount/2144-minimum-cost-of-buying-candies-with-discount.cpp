class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(),cost.end(),greater<int>());
        int ans = 0 ;
        int res = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
                ans += cost[i];
        }
        for(int i = 2 ; i < n ; i += 3)
        {
                res += cost[i];
        }

        return ans - res;

    }
};