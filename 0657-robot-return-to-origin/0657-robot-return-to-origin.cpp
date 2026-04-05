class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char,int>mp;
        mp['U'] = 1;
        mp['D'] = -1;
        mp['L'] = -1;
        mp['R'] = 1;
        int ans = 0;
        int res = 0;
        for(int i = 0 ; i < moves.size() ; i++)
        {
            if(moves[i] == 'U' || moves[i] == 'D')
            ans+=mp[moves[i]];
            if(moves[i] == 'L' || moves[i] == 'R')
            res+=mp[moves[i]];
        }
        if(ans==0 && res == 0)return true;
        else return false;

    }
};