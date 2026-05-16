class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        unordered_map<char,int> mp;
        for(char c : string("qwertyuiop"))
            mp[c] = 1;
        for(char c : string("asdfghjkl"))
            mp[c] = 2;
        for(char c : string("zxcvbnm"))
            mp[c] = 3;
        for(string word : words)
        {
            string s = word;
            for(char &c : s)
                c = tolower(c);
            int row = mp[s[0]];
            bool ok = true;
            for(char c : s)
            {
                if(mp[c] != row)
                {
                    ok = false;
                    break;
                }
            }
            if(ok)
                ans.push_back(word);
        }
        return ans;
    }
};