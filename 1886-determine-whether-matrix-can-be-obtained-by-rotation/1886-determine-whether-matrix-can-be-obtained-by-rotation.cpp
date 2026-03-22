class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int row = mat.size();
        // int col = mat[0].size();
       
        for(int k = 0 ; k < 4 ; k++)
        {
            if(mat == target) return true;

            //transpose kr diya hai ye apan ne
            for(int i = 0 ; i < row ; i++)
            {
                for(int j = i ; j < row ; j++)
                {
                    swap(mat[i][j],mat[j][i]);
                }
            }
            // ab rows ko ulta kr denge
            for(int i = 0 ; i < row ; i++)
            {
                reverse(mat[i].begin(),mat[i].end());
            }

        }
        return false;
    }
};