class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int>copy;
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i]!= 0)copy.push_back(nums[i]);
        }
        int c = copy.size();
        int t = nums.size() - copy.size();
        while(t--)
        {
            copy.push_back(0);
        }
        nums = copy;
     
    }
};