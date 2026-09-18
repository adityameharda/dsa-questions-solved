class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int count = 0 ;
        int maxi = 0 ;
        int end = 0;
        for(int i = 0 ; i < n-1 ; i++){
            if(maxi < i )return 0;
            maxi = max(maxi,i+nums[i]);
            if(i==end){
                count++;
                end = maxi;
            }   
        }
        return count ;
    }
};