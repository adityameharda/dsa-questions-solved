class Solution {
public:
    bool checkValidString(string s) {
        int pos = 0;
        int neg = 0;
        int count = 0;
        for(char ch : s){
            if(ch == '(')pos++;
            else if(ch == ')')neg++;
            else count++;
           if(neg > (pos + count)) return false;
        }
        pos = 0;
        neg = 0;
        count = 0;
        for(int i = s.length() -1  ; i >= 0; i--){
            if(s[i] == ')')pos++;
            else if(s[i] == '(')neg++;
            else count++;

            if(neg > (pos + count)) return false;
        }
        return true;
    }
};