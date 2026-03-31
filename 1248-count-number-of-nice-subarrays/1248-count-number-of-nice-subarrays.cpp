class Solution {
public:

    int solve(vector<int>& nums, int k)
    {
        if(k < 0) return 0;

        int n = nums.size();
        int i = 0;
        int count = 0;
        int ans = 0;
        for(int j = 0 ; j < n ; j++)
        {
            if(nums[j] % 2 != 0) count++;

            while(count > k)
            {
                if(nums[i] % 2 != 0) count--;
                i++;
            }

            ans += (j - i + 1);
        }

        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};



// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int n = nums.size();
//         for(int i = 0 ; i < n ; i++)
//         {
//             nums[i] = nums[i] % 2;
//         }

//         unordered_map<int,int> mp;
//         mp[0] = 1;

//         int sum = 0;
//         int ans = 0;

//         for(int i = 0 ; i < n ; i++)
//         {
//             sum += nums[i];

//             if(mp.find(sum - k) != mp.end())
//             {
//                 ans += mp[sum - k];
//             }

//             mp[sum]++;
//         }

//         return ans;
//     }
// };