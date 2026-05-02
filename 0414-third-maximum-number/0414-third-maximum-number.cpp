class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int t= 0;
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> v(s.begin(), s.end());
        sort(v.begin(), v.end(), greater<int>());
        int n = v.size();
        if(n < 3) t = v[0];
        else t = v[2];
        return t ;
    }
};