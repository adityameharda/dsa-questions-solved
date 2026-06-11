class Solution {
public:
    int minPairSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int i = 0 ;
        int j = nums.size()-1;
        vector<int>v;
        while(i<=j)
        {
            v.push_back(nums[i] + nums[j]);
            i++;
            j--;
        }
        sort(v.begin(),v.end(),greater<int>());
        return v[0] ;
    }
};