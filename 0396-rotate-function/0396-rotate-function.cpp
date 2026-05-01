class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size(); 
        int Sum = 0;
        int f0 = 0;
        for(int i = 0 ; i < n ; i++)
        {
            Sum += nums[i];
            f0 += nums[i]*i;
        }
        int maxi = f0;
        int curr = f0;
        for(int i = n-1 ; i >= 0 ; i--)
        {
            curr = curr + Sum - (n*nums[i]);
            maxi = max(maxi , curr);
        }
        return maxi;
    }
};