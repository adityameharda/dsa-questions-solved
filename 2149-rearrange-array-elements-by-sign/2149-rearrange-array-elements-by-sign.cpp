class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        // sort(nums.begin()+1,nums.end());
        vector<int>ans;
        queue<int>pos;
        queue<int>neg;
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i]>=0)pos.push(nums[i]);
            else neg.push(nums[i]);
        }
        while(!pos.empty() && !neg.empty())
        {
            ans.push_back(pos.front());
            pos.pop();
            ans.push_back(neg.front());
            neg.pop();
        }
        return ans;


        // int n = nums.size();
        // vector<int> ans(n);
        // int posidx = 0 ;
        // int negidx = 1;
        // for(int i = 0 ; i < n ; i++)
        // {
        //     if(nums[i]>=0)
        //     {
        //         ans[posidx] = nums[i];
        //         posidx +=2;
        //     }else
        //     {
        //         ans[negidx] = nums[i];
        //         negidx += 2;
        //     }
        // }
        // return ans;
    }
};