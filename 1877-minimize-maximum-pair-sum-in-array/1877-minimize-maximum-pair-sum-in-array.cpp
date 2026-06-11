class Solution {
public:
    int minPairSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int i = 0 ;
        int j = nums.size()-1;
        int t = INT_MIN ;
        int k = 0 ;
        while(i<=j)
        {
            k = nums[i] + nums[j];
            t = max(t,k);
            i++;
            j--;
        }
        return t ; 
    }
};