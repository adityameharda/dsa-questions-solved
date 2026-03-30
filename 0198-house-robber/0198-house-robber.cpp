class Solution {
public:   
     int rob(vector<int>& nums) {
    int rob1 = 0, rob2 = 0;
    for (int n : nums) {
        int newRob = max(rob2, rob1 + n);
        rob1 = rob2;
        rob2 = newRob;
    }
    return rob2;
}




//    int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) return 0;
//         if (n == 1) return nums[0];
        
//         int prev2 = nums[0];
//         int prev1 = max(nums[0], nums[1]);
        
//         for (int i = 2; i < n; i++) {
//             int curr = max(prev1, prev2 + nums[i]);
//             prev2 = prev1;
//             prev1 = curr;
//         }
//         return prev1;



        // int rob(vector<int>& nums) 
        // {
        //     int n = nums.size();
        //     int sum = 0;
        //     int sum1 = 0;
        //     int sum2 = 0;
        //     for(int i = 0 ; i < n ; i++)
        //     {
        //         sum += nums[i];
        //     }
        //     for(int i = 0 ; i < n ; i+=2)
        //     {
        //         sum1 += nums[i];
        //     }
        //     for(int i = 1 ; i < n ; i+=2)
        //     {
        //         sum2 += nums[i];
        //     }
        //     int mini = min(sum1,sum2);
        //     return sum-mini;

    // }
    
};