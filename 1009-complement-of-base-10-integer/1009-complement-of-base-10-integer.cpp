class Solution {
public:
    int bitwiseComplement(int n) {
         if(n == 0) return 1;
        string s = "";
        int x = n;
        while(x > 0)
        {
            s = char((x % 2) + '0') + s;
            x = x / 2;
        }
        int l = s.length();
        for(int i = 0 ; i < l ; i++)
        {
            if(s[i] == '1')s[i] = '0';
            else s[i] = '1';
            
        }
        return stoi(s,nullptr,2);
        

    }
};