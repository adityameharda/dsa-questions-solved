class Solution {
public:
    int minimumSum(int num) {
        vector<int>v ;
        while(num>0)
        {
            v.push_back(num%10);
            num/=10;
        }
        sort(v.begin(),v.end());
        int res = 0;
        int first = v[0];
        int second = v[1];
        int third = v[2];
        int forth = v[3];
        return res = ((first*10)+third + (second*10)+forth);
    }
};