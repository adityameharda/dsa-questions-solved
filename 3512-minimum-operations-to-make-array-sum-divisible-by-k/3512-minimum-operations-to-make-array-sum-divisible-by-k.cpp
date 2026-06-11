class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0 ;
        for(auto it : nums)
        {
            sum +=it;
        }
        if(sum < k) return sum;
        else if(sum == k)return 0;
        else{
            return sum%k;
        }
        
    }
};