// class Solution {
// public:
//     int threeSumClosest(vector<int>& nums, int target) {
//         int n = nums.size();
//         // sort(nums.begin(),nums.end());
//         // for(int i = 0 ; i < n ; i++)
//         // {
//         //     for(int j = i ; j < n ;j++)
//         //         if(nums[i] == nums[j]) continue;
//         // }
//         int res =INT_MAX ,ans = 0,t,p;
//         for(int i = 0 ; i < n ; i++)
//         {
//             for(int j = i+1 ; j < n ; j++)
//             {
//                 for(int k = j+1 ; k < n ; k++)
//                 {
//                     ans = nums[i]+nums[j]+nums[k];
//                     t = abs(ans-target);
//                     if(t < res)
//                     {
//                         res = t;
//                         p = ans;
//                     }
//                 }
//             }
//         }
//             return p;
//     }
// };


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int closest = nums[0] + nums[1] + nums[2];

        for(int i = 0; i < n - 2; i++)
        {
            int j = i + 1;
            int k = n - 1;

            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if(abs(sum - target) < abs(closest - target))
                {
                    closest = sum;
                }

                if(sum < target)
                {
                    j++;
                }
                else if(sum > target)
                {
                    k--;
                }
                else
                {
                    return sum;
                }
            }
        }

        return closest;
    }
};






