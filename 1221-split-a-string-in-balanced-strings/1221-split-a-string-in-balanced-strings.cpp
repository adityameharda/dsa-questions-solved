class Solution {
public:
    int balancedStringSplit(string s) {
        int len = s.length();
        int l = len/2;
        int ans = 0 ;
        int balance = 0 ;
        for(int i = 0 ; i < len ; i++)
        {
            if(s[i] == 'L') 
            {
                balance++;
                // if(s[i] == 'R') balance--;
                if(balance == 0) ans++;
            }
            else 
            {
                balance--;
                if(balance == 0) ans++;
            }
            // if(s[i] == 'R') 
            // {
            //     balance++;
            //     if(s[i] == 'L') balance--;
            //     if(balance == 0) ans++;
            // }
            
        }
        return ans ;


    }
};