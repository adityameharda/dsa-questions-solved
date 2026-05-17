class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> v = score;
        sort(v.begin(), v.end(), greater<int>());
        vector<string> ans;
        for(int i = 0 ; i < n ; i++)
        {
            if(score[i] == v[0])
            {
                ans.push_back("Gold Medal");
            }
            else if(n > 1 && score[i] == v[1])
            {
                ans.push_back("Silver Medal");
            }
            else if(n > 2 && score[i] == v[2])
            {
                ans.push_back("Bronze Medal");
            }
            else
            {
                for(int j = 0 ; j < n ; j++)
                {
                    if(score[i] == v[j])
                    {
                        ans.push_back(to_string(j + 1));
                    }
                }
            }
        }
        return ans;
    }
};