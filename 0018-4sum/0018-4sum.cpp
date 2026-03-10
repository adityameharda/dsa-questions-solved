// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         set<vector<int>> st;

//         for(int i = 0; i < n; i++)
//         {
//             for(int j = i + 1; j < n; j++)
//             {
//                 for(int k = j + 1; k < n; k++)
//                 {
//                     for(int l = k + 1; l < n; l++)
//                     {
//                         long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

//                         if(sum == target)
//                         {
//                             st.insert({nums[i], nums[j], nums[k], nums[l]});
//                         }
//                     }
//                 }
//             }
//         }

//         vector<vector<int>> res(st.begin(), st.end());
//         return res;
//     }
// };



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;

        for(int i = 0; i < n - 3; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            for(int j = i + 1; j < n - 2; j++)
            {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;

                int k = j + 1;
                int l = n - 1;

                while(k < l)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if(sum == target)
                    {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;

                        while(k < l && nums[k] == nums[k - 1]) k++;
                        while(k < l && nums[l] == nums[l + 1]) l--;
                    }
                    else if(sum < target)
                    {
                        k++;
                    }
                    else
                    {
                        l--;
                    }
                }
            }
        }

        return res;
    }
};