class Solution {
public:
    int countHomogenous(string s) {
        int len = 1 ;
        int ans = 1;
        int mod = 1000000007;
        char curr = s[0];
        // for(char ch : s){
        //     if(ch == curr){
        //         len++;
        //         ans = (ans+len)%mod;
        //     }else{
        //         len = 1;
        //         ans = (ans + len)%mod;
        //     }
        // }
        for(int i = 1 ; i < s.length() ; i++){
            if(s[i] == curr){
                len++;
                ans = (ans%mod+len)%mod;
            }
            else{
                len = 1;
                curr = s[i];
                ans= (ans%mod+len)%mod;
            }
        }
        return ans;
    }
};