class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>>pq;

        for(int i = 0 ; i < n ; i++)
        {
            pq.push({nums[i],i});
        }
        vector<int>ans;
        while(k--)
        {
            auto[val,idx] = pq.top();
            pq.pop();
            nums[idx] *= multiplier;
            pq.push({nums[idx],idx});
        }
        return  nums;
    }
};