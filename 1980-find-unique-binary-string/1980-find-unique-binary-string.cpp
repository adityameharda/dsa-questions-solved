class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        vector<int> v;
        for(int i = 0; i < n; i++)
        {
            int t = stoi(nums[i], 0, 2); 
            v.push_back(t);
        }
        sort(v.begin(), v.end());
        int y = 0;
        int c = 2*n;
        for(int i = 0 ; i < c ; i++) 
        {
            if(i >= v.size() || i != v[i])
            {
                y = i ;
                break;
            }
        }
        // string ans = "";
        // for(int i = n - 1; i >= 0; i--)
        // {
        //     if(y & (1 << i)) ans += '1';
        //     else ans += '0';
        // }
        string ans = bitset<16>(y).to_string().substr(16-n);

        return ans;
    }
};