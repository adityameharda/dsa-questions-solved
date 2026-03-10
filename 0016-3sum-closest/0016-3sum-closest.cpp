class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        // for(int i = 0 ; i < n ; i++)
        // {
        //     for(int j = i ; j < n ;j++)
        //         if(nums[i] == nums[j]) continue;
        // }
        int res =INT_MAX ,ans = 0,t,p;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i+1 ; j < n ; j++)
            {
                for(int k = j+1 ; k < n ; k++)
                {
                    ans = nums[i]+nums[j]+nums[k];
                    t = abs(ans-target);
                    if(t < res)
                    {
                        res = t;
                        p = ans;
                    }
                }
            }
        }
            return p;
    }
};