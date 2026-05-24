class Solution {
public:
    vector<int> diStringMatch(string s) {
        int l = s.length();
        vector<int>res ;
        int low = 0 ;
        int high = l;
        for(int i = 0 ; i < l ; i++)
        {
            if(s[i] == 'I')
            {
                res.push_back(low);
                low++;
            }
            if(s[i] == 'D')
            {
                res.push_back(high);
                high--;
            }
        }
        res.push_back(low);
        return res;
    }
};