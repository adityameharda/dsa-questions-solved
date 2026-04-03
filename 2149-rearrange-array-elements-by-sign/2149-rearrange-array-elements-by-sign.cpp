class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // int n = nums.size();
        // // sort(nums.begin()+1,nums.end());
        // vector<int>ans;
        // queue<int>pos;
        // queue<int>neg;
        // for(int i = 1 ; i < n ; i++)
        // {
        //     if(nums[i]>=0)pos.push(nums[i]);
        //     else neg.push(nums[i]);
        // }
        // ans.push_back(nums[0]);
        // while(!pos.empty())
        // {
        //     int top = neg.top();
        //     ans.push_back(top);
        //     neg.pop();
        //     int top2 = pos.top();
        //     ans.push_back(top2);
        //     pos.pop();
        // }
        // return ans;


        int n = nums.size();
        vector<int> ans(n);
        int posidx = 0 ;
        int negidx = 1;
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i]>=0)
            {
                ans[posidx] = nums[i];
                posidx +=2;
            }else
            {
                ans[negidx] = nums[i];
                negidx += 2;
            }
        }
        return ans;
    }
};