class Solution {
public:
    int minPartitions(string n) {
        int t = 0;
        vector<int> v;
        for(char ch : n) 
        {
            v.push_back(ch - '0');
        }
        // if (t < 10)
        //     return t;
        // while (t > 0) 
        // {
        //     int l = t % 10;
        //     v.push_back(l);
        //     t /= 10;
        // }
        sort(v.begin(),v.end(),greater<int>());

        return v[0];
    }
};