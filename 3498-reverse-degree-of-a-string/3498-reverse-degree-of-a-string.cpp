class Solution {
public:
    int reverseDegree(string s) {
        vector<int>arr(26,0);
        int n = s.length();
        int sum = 0 ;
        int rev = 0 ;
        for(int i = 0 ; i < n; i++){
            rev = 'z' - s[i] +1;
            sum += rev * (i+1);
        }
 
        return sum ;

    }
};