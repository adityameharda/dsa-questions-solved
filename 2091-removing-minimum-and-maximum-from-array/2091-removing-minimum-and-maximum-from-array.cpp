class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int idx1 = 0,idx2 = 0;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int n = nums.size();

        for(int i = 0; i< n; i++){
            if(mini > nums[i]){
                mini = nums[i];
                idx1 = i;
            }
        }
        for(int i = 0; i< n; i++){
            if(maxi < nums[i]){
                maxi = nums[i];
                idx2 = i;
            }
        }
        int l = min(idx1, idx2);
        int h = max(idx1, idx2);
       
        // 1
       int left = h+1;
       int right = n-l;
       int both = l+1+n-h;
       return min(left,min(right,both));
    }
};