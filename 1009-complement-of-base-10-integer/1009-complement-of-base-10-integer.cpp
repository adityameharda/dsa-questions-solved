class Solution {
public:
    int bitwiseComplement(int n) {
         if(n == 0) return 1;
        string s;

        for(int x = n; x > 0; x /= 2)
        {
            s = char((x % 2) + '0') + s;
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